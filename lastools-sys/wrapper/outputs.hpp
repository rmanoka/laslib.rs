#pragma once

#include <clang/AST/ASTConsumer.h>
#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/Sema/SemaConsumer.h>
#include <iostream>
#include <llvm/Support/CommandLine.h>
#include <string>

using namespace clang;
using namespace llvm;
using namespace std;

class OutputStreams {
private:
  PrintingPolicy *pp;

  const CXXRecordDecl *recordDecl;
  string recordName;
  bool recordAllowed;
  map<string, int> overloads;

  const CXXMethodDecl *method;
  string methodName;
  string returnType;
  string selfType;
  bool hasSelf;
  string funcBody;
  string funcSuffix;
  vector<string> params;
  vector<string> param_types;

  const FieldDecl *field;

protected:
  string headerString;
  string bodyString;
  llvm::raw_string_ostream header;
  llvm::raw_string_ostream body;

  bool generateConstructor(const CXXConstructorDecl *ccd) {
    // cerr << "Constructor" << endl;
    // ccd->dump();
    if (recordDecl->isAbstract())
      return false;
    if (ccd->isCopyConstructor())
      return false;
    if (ccd->isMoveConstructor())
      return false;
    if (ccd->isPure())
      return false;
    methodName = "_create";
    returnType = "void *";
    hasSelf = false;
    funcBody = "return reinterpret_cast<"
      + returnType + ">(new "
      + recordName + "(";
    funcSuffix = "));\n";
    return true;
  }
  bool generateDestructor() {
    methodName = "_destroy";
    returnType = "void ";
    selfType = recordName + " *";
    hasSelf = true;
    funcBody = "delete reinterpret_cast<"
      + recordName + "*>(self";
    funcSuffix = ");\n";
    return true;
  }

  bool printType(const QualType &ty, string &out, bool simplify=true) {
    out.clear();
    raw_string_ostream s(out);
    if (ty->isBuiltinType()) {
      if (!simplify) return true;
      ty.print(s, *pp);
    } else if (!simplify) {
      ty.print(s, *pp);
    } else if (ty->isPointerType()) {
      auto teety = ty->getPointeeType();
      if (teety.isConstQualified()) { s << "const "; }
      s << "void *";
    } else {
      return false;
    }
    s.flush();
    return true;
  }

  bool generateRegularMethod() {
    auto name = method->getNameAsString();
    methodName = "_" + name;

    if (!printType(method->getReturnType(), returnType)) return false;
    returnType += " ";

    if (method->isStatic()) {
      hasSelf = false;
    } else {
      hasSelf = true;
      if (!printType(method->getThisType(), selfType)) return false;
      printType(method->getThisType(), selfType, false);
    }

    funcBody = "";
    funcSuffix = ";";
    if (returnType != "void ") {
      funcBody += "return ";
      if (!method->getReturnType()->isBuiltinType()) {
        funcBody += "reinterpret_cast<" + returnType + ">(";
        funcSuffix = ")" + funcSuffix;
      }
    }
    if (hasSelf) {
      funcBody += "reinterpret_cast<" + selfType
        + ">(self)->" + name + "(";
      funcSuffix = ")" + funcSuffix;
    } else {
      funcBody += recordName + "::" + name + "(";
      funcSuffix = ")" + funcSuffix;
    }
    return true;
  }

  bool parseArguments(string &buffer) {
    // cerr << "Parsing " << method->getNumParams()
    //      << " args of " << method->getQualifiedNameAsString() << endl;
    raw_string_ostream s(buffer);

    auto idx = overloads[methodName];
    s << returnType << recordName << methodName;
    if (idx > 0) {
      s << "_" << idx;
    }

    s << "(";
    params.clear();
    param_types.clear();

    if (hasSelf) {
      s << "void *self";
    }

    for (unsigned int i = 0; i < method->getNumParams(); i++) {
      ParmVarDecl *param = method->parameters()[i];
      const QualType qt = param->getType();

      param->setDefaultArg(0);

      auto name = param->getQualifiedNameAsString();
      string cty, ty;
      if (!printType(qt, cty)) return false;
      printType(qt, ty, false);

      params.push_back(name);
      param_types.push_back(ty);

      if ((i != 0) || hasSelf) {
        s << ", ";
      }

      s << cty << " " << name;

    }
    s << ")";
    s.flush();
    return true;
  }

  void generateCallParams() {
    for (auto i=0; i<params.size(); i++) {
      if (i != 0) body << ", ";
      if (param_types[i].size()) {
        body << "\n\treinterpret_cast<" << param_types[i] << ">";
        body << "(" << params[i] << ")";
      } else {
        body << params[i];
      }
    }
  }

public:
  OutputStreams() : headerString(""), bodyString(""),
                    header(headerString), body(bodyString) {};

  bool allowClassByDecl(const CXXRecordDecl *decl) {
    recordDecl = decl;
    recordName = decl->getQualifiedNameAsString();
    if (!decl->isThisDeclarationADefinition()
        || !(recordName.rfind("LAS", 0) == 0))
      return recordAllowed = false;
    // cerr << "Record: " << recordName << endl;
    return recordAllowed = true;
  }

  bool allowMethodByDecl(const CXXMethodDecl *method) {
    // Is this class to be generated?
    if (!recordAllowed)
      return false;

    // Is this method public?
    if (!(method->getAccess() == AccessSpecifier::AS_public))
      return false;

    // No operator overloading
    if (method->isOverloadedOperator())
      return false;
    if (method->isPure())
      return false;

    this->method = method;
    return true;
  }

  bool allowFieldByDecl(const FieldDecl *field) {
    // Is this class to be generated?
    if (!recordAllowed)
      return false;

    // Is this field public?
    if (!(field->getAccess() == AccessSpecifier::AS_public))
      return false;
    if (field->isBitField()) return false;

    this->field = field;
    return true;
  }

  void generateRecordWrapper() {
    header << "\n\n"
           << "// " << recordName
           << "\n";
    body << "\n\n"
         << "// " << recordName
         << "\n";

    overloads.clear();
  }
  void generateMethod() {
    if (const CXXConstructorDecl *ccd = dyn_cast<CXXConstructorDecl>(method)) {
      if (!generateConstructor(ccd)) return;
    } else if (isa<CXXDestructorDecl>(method)) {
      if (!generateDestructor()) return;
    } else {
      if (!generateRegularMethod()) return;
    }

    auto exists = overloads.find(methodName);
    auto idx = 0;
    if (exists != overloads.end()) {
      ++(exists->second);
    } else {
      overloads[methodName] = 0;
    }

    string buffer;
    if (!parseArguments(buffer))
      return;

    header << buffer;
    body << buffer;

    header << ";\n";

    body << "{\n  " << funcBody;
    generateCallParams();
    body << funcSuffix << "}\n";
  }

  void generateField() {
    auto fieldName = field->getNameAsString();
    methodName = "_field_" + fieldName;

    returnType.clear();
    {
      raw_string_ostream s(returnType);
      auto ty = field->getType();

      if (ty.isConstQualified()) {
        s << "const ";
      }
      if (ty->isBuiltinType()) {
        ty.print(s, *pp);
      } else {
        s << "void";
      }
      s << " *";
      s.flush();
    }

    string buffer;
    raw_string_ostream bs(buffer);
    bs << returnType << recordName << methodName
       << "(void *self)";
    bs.flush();

    header << buffer << ";\n";
    body << buffer << " {\n";
    body << "\treturn reinterpret_cast<" << returnType
         << ">(\n\t\t&reinterpret_cast<" << recordName
         << " *>(self)->" << fieldName << ");\n";
    body << "}\n";
  }

  void start(StringRef file) {
    header << "#ifndef __CWRAPPER_H\n"
      "#define __CWRAPPER_H_\n"

      "#ifdef __cplusplus\n"
      "extern \"C\"{\n"
      "#endif\n";

    body << "#include \"cwrapper.h\"\n"
         << "#include \"" << file << "\"\n"
      "#ifdef __cplusplus\n"
      "extern \"C\"{\n"
      "#endif\n";
  }
  void finish() {
    header << "#ifdef __cplusplus\n"
      "}\n"
      "#endif\n"
      "#endif /* CWRAPPER_H_ */\n";

    body << "#ifdef __cplusplus\n"
      "}\n"
      "#endif\n";

  }

  const string &getHeader() {
    header.flush();
    return headerString;
  }
  const string &getBody() {
    body.flush();
    return bodyString;
  }
  void setPP(PrintingPolicy *pp) {
    this->pp = pp;
  }
};

#include "outputs.hpp"

#include <clang/AST/ASTConsumer.h>
#include <clang/AST/RecursiveASTVisitor.h>

#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace clang;
using namespace std;

bool allowClassByQN(const string &name) { return (name.rfind("LAS", 0) == 0); }

tuple<string, string, bool, bool> determineCType(const QualType &qt) {

  string CType = "";
  string CastType = ""; // whether this should be casted or not
  bool isPointer = false;
  bool shoulReturn = true;

  CType = qt.getAsString();
  // if it is builtin type use it as is
  if (qt->isBuiltinType() ||
      (qt->isPointerType() && qt->getPointeeType()->isBuiltinType())) {
    CType = qt.getAsString();
    if (qt->isVoidType())
      shoulReturn = false;
    // if it is a CXXrecordDecl then return a pointer to WName*
  } else if (qt->isRecordType()) {
    const CXXRecordDecl *crd = qt->getAsCXXRecordDecl();
    string recordName = crd->getNameAsString();
    CType = "W" + recordName + "*";
    CastType = recordName + "*";

  } else if ((qt->isReferenceType() || qt->isPointerType()) &&
             qt->getPointeeType()->isRecordType()) {
    isPointer = true; // to properly differentiate among cast types
    const CXXRecordDecl *crd = qt->getPointeeType()->getAsCXXRecordDecl();
    auto className = crd->getQualifiedNameAsString();
    if (allowClassByQN(className)) {
      std::replace(className.begin(), className.end(), ':', '_');
      CType = "W" + className + "*";
      CastType = className + "*";
    } else {
      CType = className + "*";
    }
  }
  return make_tuple(CType, CastType, isPointer, shoulReturn);
}

class FindNamedClassVisitor
    : public RecursiveASTVisitor<FindNamedClassVisitor> {

  map<string, int> overloads;
  OutputStreams &out;

public:
  FindNamedClassVisitor(OutputStreams &out) : out(out) {}

  bool VisitCXXRecordDecl(CXXRecordDecl *decl) {

    auto className = decl->getQualifiedNameAsString();
    if (!allowClassByQN(className))
      return true;
    cerr << "class " << className << endl;

    decl->dump();

    std::replace(className.begin(), className.end(), ':', '_');
    out.header << "struct      W" << className << "; \n"
               << "typedef     struct W" << className << " W" << className
               << ";\n";
    // The return value indicates whether we want the visitation to proceed.
    // Return false to stop the traversal of the AST.
    return true;
  }

  bool VisitCXXMethodDecl(CXXMethodDecl *method) {
    // Is this class to be generated?
    auto className = method->getParent()->getQualifiedNameAsString();
    if (!allowClassByQN(className))
      return true;

    // Is this method public?
    if (!(method->getAccess() == AccessSpecifier::AS_public))
      return true;

    // No operator overloading
    if (method->isOverloadedOperator())
      return true;

    cerr << "\t" << method->getNameAsString() << endl;

    // Replace all :: with __
    std::replace(className.begin(), className.end(), ':', '_');

    string methodName = "";
    string returnType = "";
    string returnCast = "";
    bool shouldReturn, isPointer;
    string self = "W" + className + "* self";
    string separator = ", ";
    string bodyEnd = "";
    stringstream functionBody;
    std::stringstream comment;

    if (const CXXConstructorDecl *ccd = dyn_cast<CXXConstructorDecl>(method)) {
      if (ccd->isCopyConstructor() || ccd->isMoveConstructor())
        return true;
      if (ccd->isPure()) return true;
      methodName = "_create";
      returnType = "W" + className + "*";
      self = "";
      separator = "";
      functionBody << "return reinterpret_cast<" << returnType << ">( new "
                   << className << "(";
      bodyEnd += "))";
    } else if (isa<CXXDestructorDecl>(method)) {
      methodName = "_destroy";
      returnType = "void";
      functionBody << " delete reinterpret_cast<" << className << "*>(self)";
    } else {
      methodName = "_" + method->getNameAsString();
      const QualType qt = method->getReturnType();
      comment << "// Method " << qt.getAsString() << " " << methodName << endl;
      std::tie(returnType, returnCast, isPointer, shouldReturn) =
          determineCType(qt);

      // should this function return?
      if (shouldReturn)
        functionBody << "return ";

      if (returnCast != "") {
        // if not pointer and it needs to be casted, then return the pointer
        if (!isPointer)
          functionBody << "&";
        functionBody << "reinterpret_cast<" << returnType << ">(";
        bodyEnd += ")";
      }

      // if Static call it properly
      if (method->isStatic())
        functionBody << className << "::" << method->getNameAsString() << "(";
      // if not  use the passed object to call the method
      else
        functionBody << "reinterpret_cast<" << className << "*>(self)->"
                     << method->getNameAsString() << "(";

      bodyEnd += ")";
    }
    std::stringstream funcname;

    funcname << returnType << " " << className << methodName;
    comment << "// " << className << methodName << endl;

    string ovid = "";
    ovid += className;
    ovid += methodName;
    auto it = overloads.find(ovid);

    if (it != overloads.end()) {
      it->second++;
      funcname << "_" << it->second;
    } else {
      overloads[ovid] = 0;
    }

    funcname << "(" << self;
    for (unsigned int i = 0; i < method->getNumParams(); i++) {
      const auto param = method->parameters()[i];
      const QualType qt = param->getType();
      comment << "// "
              << "arg "
                 << i << ": "
                 << qt.getAsString() << " "
                 << param->getQualifiedNameAsString()
              << endl;

      std::tie(returnType, returnCast, isPointer, shouldReturn) =
          determineCType(qt);
      funcname << separator << returnType << " ";
      funcname << method->parameters()[i]->getQualifiedNameAsString() << "";

      if (i != 0)
        functionBody << separator;
      if (returnCast == "")
        functionBody << method->parameters()[i]->getQualifiedNameAsString();
      else {
        if (!isPointer)
          functionBody << "*";
        functionBody << "reinterpret_cast<" << returnCast << ">("
                     << method->parameters()[i]->getQualifiedNameAsString() << ")";
      }

      separator = ", ";
    }
    funcname << ")";

    out.header << comment.str();
    out.header << funcname.str() << ";\n";

    out.body << funcname.str() << "{\n    ";
    out.body << functionBody.str();
    out.body << bodyEnd << "; \n}\n";
    return true;
  }

  bool VisitFieldDecl(FieldDecl *field) {
    auto className = field->getParent()->getQualifiedNameAsString();
    if (!allowClassByQN(className))
      return true;
    if (!(field->getAccess() == AccessSpecifier::AS_public))
      return true;

    cerr << "  field: " << field->getNameAsString() << endl;
    return true;
  }
};

class Consumer : public ASTConsumer {
public:
  Consumer(OutputStreams &out) : visitor(out) {}
  virtual void HandleTranslationUnit(clang::ASTContext &Context) {
    // Traversing the translation unit decl via a RecursiveASTVisitor
    // will visit all nodes in the AST.
    visitor.TraverseDecl(Context.getTranslationUnitDecl());
  }

private:
  // A RecursiveASTVisitor implementation.
  FindNamedClassVisitor visitor;
};

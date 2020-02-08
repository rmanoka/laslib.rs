#include "outputs.hpp"

#include <clang/AST/ASTConsumer.h>
#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/Sema/SemaConsumer.h>

#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace clang;
using namespace std;

class SemaVisitor
    : public RecursiveASTVisitor<SemaVisitor> {

  map<string, int> overloads;
  OutputStreams &out;

public:
  SemaVisitor(OutputStreams &out) : out(out) {}

  void setPP(PrintingPolicy *pp) {
    out.setPP(pp);
  }

  bool VisitCXXRecordDecl(CXXRecordDecl *decl) {
    if (!out.allowClassByDecl(decl))
      return true;

    out.generateRecordWrapper();
    // The return value indicates whether we want the visitation to proceed.
    // Return false to stop the traversal of the AST.
    return true;
  }

  bool VisitCXXMethodDecl(CXXMethodDecl *method) {
    // Is this method to be generated?
    if (!out.allowMethodByDecl(method)) return true;
    out.generateMethod();
    return true;
  }

  bool VisitFieldDecl(FieldDecl *field) {
    if (!out.allowFieldByDecl(field)) return true;
    out.generateField();
    return true;
  }
};

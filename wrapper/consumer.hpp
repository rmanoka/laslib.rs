#include "outputs.hpp"
#include "visitor.hpp"

#include <clang/Sema/SemaConsumer.h>
#include <clang/AST/ASTConsumer.h>
#include <clang/AST/RecursiveASTVisitor.h>

#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace clang;
using namespace std;


class Consumer : public ASTConsumer {
public:
  Consumer(OutputStreams &out) : visitor(out) {}
  virtual void HandleTranslationUnit(clang::ASTContext &Context) {
    // Traversing the translation unit decl via a RecursiveASTVisitor
    // will visit all nodes in the AST.
    auto pp = Context.getPrintingPolicy();
    pp.PrintCanonicalTypes = 1;
    visitor.setPP(&pp);
    visitor.TraverseDecl(Context.getTranslationUnitDecl());
  }

private:
  // A RecursiveASTVisitor implementation.
  SemaVisitor visitor;
};

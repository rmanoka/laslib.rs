#include <clang/ASTMatchers/ASTMatchFinder.h>
#include <clang/ASTMatchers/ASTMatchers.h>
#include <clang/Frontend/FrontendActions.h>
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>
#include <iostream>
#include <llvm/Support/CommandLine.h>

#include "options.hpp"
#include "actions.hpp"

using namespace llvm;
using namespace clang;
using namespace clang::ast_matchers;
using namespace clang::tooling;
using namespace std;

// DeclarationMatcher LoopMatcher =
//   cxxMethodDecl(
//                 isPublic(),
//                 unless(isImplicit())).bind("method");

// class Printer : public MatchFinder::MatchCallback {
// public:
//   virtual void run(const MatchFinder::MatchResult &Result) {
//     if (const CXXMethodDecl *FS = Result.Nodes.getNodeAs<clang::CXXMethodDecl>("method")) {
//       const auto* klass = FS->getParent();
//       cout << klass->getNameAsString() << "::";
//       cout << FS->getNameAsString() << endl;
//       // FS->dump();
//     }
//   }
// };


int main(int argc, const char **argv) {
  CommonOptionsParser OptionsParser(argc, argv, MyToolCategory);
  ClangTool Tool(OptionsParser.getCompilations(),
                 OptionsParser.getSourcePathList());

  return Tool.run(newFrontendActionFactory<Action>()
                  .get());
}

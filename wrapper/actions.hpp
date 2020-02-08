#include <clang/Frontend/FrontendActions.h>
#include <clang/Sema/SemaConsumer.h>

#include "outputs.hpp"
#include "consumer.hpp"

using namespace llvm;
using namespace clang;

class Action : public ASTFrontendAction {
public:
  Action() {
  }

  void EndSourceFileAction() override {
    StringRef headerFile("cwrapper.h");
    StringRef bodyFile("cwrapper.cpp");

    // Open the output file
    std::error_code EC;
    llvm::raw_fd_ostream HOS(headerFile, EC, llvm::sys::fs::F_None);
    if (EC) {
      llvm::errs() << "while opening '" << headerFile << "': " << EC.message()
                   << '\n';
      exit(1);
    }
    llvm::raw_fd_ostream BOS(bodyFile, EC, llvm::sys::fs::F_None);
    if (EC) {
      llvm::errs() << "while opening '" << bodyFile << "': " << EC.message()
                   << '\n';
      exit(1);
    }
    out.finish();
    HOS << out.getHeader() << "\n";
    BOS << out.getBody() << "\n";
  }

  std::unique_ptr<ASTConsumer>
  CreateASTConsumer(CompilerInstance &CI,
                    StringRef file) override {
    out.start(file);
    return llvm::make_unique<Consumer>(out);
  }

private:
  OutputStreams out;
};

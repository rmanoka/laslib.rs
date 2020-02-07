#include <clang/Frontend/FrontendActions.h>

#include "outputs.hpp"
#include "consumer.hpp"

using namespace llvm;
using namespace clang;

class Action : public ASTFrontendAction {
public:
  Action() {
    out.header << "#ifndef __CWRAPPER_H\n"
      "#define __CWRAPPER_H_\n"

      "#include <stdbool.h>\n"
      "#include <lasreader_las.hpp>\n"

      "#ifdef __cplusplus\n"
      "extern \"C\"{\n"
      "#endif\n";

    out.body
        << "#include \"cwrapper.h\"\n"
           "#ifdef __cplusplus\n"
           "extern \"C\"{\n"
           "#endif\n";
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

    out.header << "#ifdef __cplusplus\n"
                   "}\n"
                   "#endif\n"
                   "#endif /* CWRAPPER_H_ */\n";

    out.body << "#ifdef __cplusplus\n"
                 "}\n"
                 "#endif\n";

    out.header.flush();
    out.body.flush();
    HOS << out.headerString << "\n";
    BOS << out.bodyString << "\n";
  }

  std::unique_ptr<ASTConsumer>
  CreateASTConsumer(CompilerInstance &CI,
                    StringRef file) override {
    return llvm::make_unique<Consumer>(out);
  }

private:
  OutputStreams out;
};

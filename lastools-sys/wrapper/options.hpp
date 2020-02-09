#include <clang/Tooling/CommonOptionsParser.h>
#include <llvm/Support/CommandLine.h>

using namespace llvm;
using namespace clang;
using namespace clang::tooling;

// Apply a custom category to all command-line options so that they are the
// only ones displayed.
static llvm::cl::OptionCategory MyToolCategory("c-wrap-gen options");

// CommonOptionsParser declares HelpMessage with a description of the common
// command-line options related to the compilation database and input files.
// It's nice to have this help message in all tools.
static cl::extrahelp CommonHelp(CommonOptionsParser::HelpMessage);

// A help message for this specific tool can be added afterwards.
static cl::extrahelp MoreHelp("\nCreate a C wrapper for C++ classes\n");

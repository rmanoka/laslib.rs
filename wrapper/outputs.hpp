#pragma once

#include <llvm/Support/CommandLine.h>
#include <string>

using std::string;

struct OutputStreams {
  string headerString;
  string bodyString;
  llvm::raw_string_ostream header;
  llvm::raw_string_ostream body;

  OutputStreams() : headerString(""), bodyString(""),
                    header(headerString), body(bodyString) {};
};

#include <iostream>
#include <fstream>
#include <jdksmidi/world.h>
#include "MuseLexer.h"
#include "MuseParser.h"
#include "MuseMidiCompiler.h"

int main(int argc, char* argv[]) {
    if(argc < 2) {
        std::cout << "usage: compiler <input path>" << std::endl;
        return -1;
    }

    // read input
    std::string inputPath{argv[1]};
    std::ifstream is{inputPath};
    std::string content{std::istreambuf_iterator<char>(is), std::istreambuf_iterator<char>()};

    // lex input
    dem::lexer::MuseLexer museLexer;
    auto begin = content.begin();
    auto end = content.end();
    std::vector<dem::lexer::Token> tokens = museLexer.lex(begin, end);

    // parse input
    dem::parser::MuseParser museParser;
    dem::parser::ParseResults results = museParser.parse(tokens);

    if(results.successful()) {
        // compile input
        dem::compiler::MidiCompiler midiCompiler;
        midiCompiler.compile(static_cast<dem::parser::Program*>(results.astRoot), "test.mid");
    }

    return 0;
}
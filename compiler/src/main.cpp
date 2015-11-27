#include <iostream>
#include <fstream>
#include "MuseLexer.h"
#include "MuseParser.h"
#include "MidiCompiler.h"

int main(int argc, char* argv[]) {
    std::cout << argv[0] << ":" << argv[1] << std::endl;
    if(argc < 2) {
        std::cout << "usage: compiler <input path>" << std::endl;
        return -1;
    }

    try {
        std::string inputPath{argv[1]};
        std::ifstream is{inputPath};
        std::string content{std::istreambuf_iterator<char>(is), std::istreambuf_iterator<char>()};

        // lex input
        dem::lexer::MuseLexer museLexer;
        std::vector<dem::lexer::Token> tokens = museLexer.lex(content.begin(), content.end());

        // parse input
        dem::parser::MuseParser museParser;
        dem::parser::Symbol *program = museParser.parse(tokens);

        // compile input
        dem::compiler::MidiCompiler midiCompiler;
        midiCompiler.compile(static_cast<dem::parser::Program*>(program));
    } catch(...) {
        std::cout << "WTF" << std::endl;
    }
}
#include <fstream>
#include <iostream>
#include "MuseLexer.h"
#include "MuseParser.h"
#include "symbol/Program.h"

int main(int argc, char* argv[]) {
    if(argc < 2) {
        std::cout << "usage: compiler <input path>" << std::endl;
        return -1;
    }

    std::string inputPath{argv[1]};
    std::ifstream is{inputPath};
    std::string content{std::istreambuf_iterator<char>(is), std::istreambuf_iterator<char>()};

    // lex input
    dem::lexer::MuseLexer museLexer;
    std::vector<dem::lexer::Token> tokens = museLexer.lex(content.begin(), content.end());

    // parse
    dem::parser::MuseParser museParser;
    dem::parser::Symbol *program = museParser.parse(tokens);
    std::cout << "Done!" << std::endl;
}

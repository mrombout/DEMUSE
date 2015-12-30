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
    auto begin = content.begin();
    auto end = content.end();

    // lex input
    dem::lexer::MuseLexer museLexer;
    std::vector<dem::lexer::Token> tokens = museLexer.lex(begin, end);

    // parse
    dem::parser::MuseParser museParser;
    dem::parser::ParseResults parseResults = museParser.parse(tokens);
    std::cout << "Done!" << std::endl;
}

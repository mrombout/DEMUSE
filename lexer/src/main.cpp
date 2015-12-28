#include <fstream>
#include <iomanip>
#include <iostream>
#include "MuseLexer.h"

int main(int argc, char* argv[]) {
    if(argc < 2) {
        std::cout << "usage: lexer <input_path>" << std::endl;
        return -1;
    }

    std::string inputPath{argv[1]};
    std::ifstream is{inputPath};

    std::string content{std::istreambuf_iterator<char>(is), std::istreambuf_iterator<char>()};
    auto begin = content.begin();
    auto end = content.end();

    dem::lexer::MuseLexer lexer;
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end, false);

    std::cout << "  +----------------------+--------------+------------+------------+-------+\n";
    std::cout << "  | " << std::left << std::setw(20) << "Content" << " | " << std::setw(12) << "Type" << " | " << std::setw(10) << "Line" << " | " << std::setw(10) << "Column" << " | " << std::setw(5) << "Index |\n";
    std::cout << "  +----------------------+--------------+------------+------------+-------+\n";
    for(dem::lexer::Token &token : tokens) {
        std::cout << "  | " << std::left << std::setw(20) << token.content() << " | " << std::right << std::setw(12) << token.type() << " | " << std::setw(10) << token.line() << " | " << std::setw(10) << token.column() << " | " << std::setw(5) << token.startIndex() << " |" << std::endl;
    }
    std::cout << "  +----------------------+--------------+------------+------------+-------+\n" << std::endl;
}

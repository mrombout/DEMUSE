#include <iostream>
#include "Lexer.h"

namespace dem {
    namespace lexer {
        Lexer::Lexer() :
            mNewLineMatcher("\\r\\n|\\n"),
            mSkipWhitespaceMatcher("\\s*"){

        }

        Lexer::~Lexer() {
            for(auto *tokenDefinition : mTokenDefinitions) {
                delete tokenDefinition;
            }
        }

        void Lexer::addDefinition(TokenDefinition *tokenDefinition) {
            mTokenDefinitions.push_back(tokenDefinition);
        }

        std::vector<Token> Lexer::lex(std::string::iterator begin, std::string::iterator end) {
            std::vector<Token> tokens;

            int curLine = 1;
            int curColumn = 1;
            int curIndex = 0;

            while(begin != end) {
                match(tokens, begin, end, curLine, curColumn, curIndex);

                std::string newLine;
                if((newLine = mNewLineMatcher.match(begin, end)).length() > 0) {
                    ++curLine;
                    curColumn = 1;
                    curIndex += newLine.size();
                    std::advance(begin, newLine.length());
                    continue;
                }

                int skippedWhitespace = mSkipWhitespaceMatcher.match(begin, end).length();
                curIndex += skippedWhitespace;
                curColumn += skippedWhitespace;
                std::advance(begin, skippedWhitespace);
            }

            return tokens;
        }

        void Lexer::match(std::vector<Token> &tokens, std::string::iterator &begin, std::string::iterator &end, int &curLine, int &curColumn, int &curIndex) {
            for(TokenDefinition *tokenDefinition : mTokenDefinitions) {
                std::string matched = tokenDefinition->matcher().match(begin, end);

                if(matched.length() > 0) {
                    std::advance(begin, matched.length());
                    tokens.push_back(Token(tokenDefinition->type(), matched, curIndex, curLine, curColumn));

                    curColumn += matched.length();
                    curIndex += matched.length();

                    return;
                }
            }
        }
    }
}

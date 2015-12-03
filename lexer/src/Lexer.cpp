#include <iostream>
#include "Lexer.h"
#include "TokenType.h"

namespace dem {
    namespace lexer {
        Lexer::Lexer() :
            Lexer(nullptr) {

        }

        Lexer::Lexer(Matcher *stopMatcher) :
            mNewLineMatcher("\\r\\n?|\\n"),
            mSkipMatcher("\\s*"),
            mStopMatcher(stopMatcher) {

        }

        Lexer::~Lexer() {
            for(auto *tokenDefinition : mTokenDefinitions) {
                delete tokenDefinition;
            }
        }

        void Lexer::addDefinition(TokenDefinition *tokenDefinition) {
            mTokenDefinitions.push_back(tokenDefinition);
        }

        std::vector<Token> Lexer::lex(std::string::iterator &begin, std::string::iterator &end) const {
            std::vector<Token> tokens;

            int curLine = 1;
            int curColumn = 1;
            int curIndex = 0;

            while(begin != end) {
                // should we stop?
                if(mStopMatcher && mStopMatcher->match(begin, end, tokens).length() > 0)
                    return tokens;

                // match single token
                bool matched = match(tokens, begin, end, curLine, curColumn, curIndex);

                // skip newlines
                std::string newLine;
                if((newLine = mNewLineMatcher.match(begin, end, tokens)).length() > 0) {
                    ++curLine;
                    curColumn = 1;
                    curIndex += newLine.size();
                    std::advance(begin, newLine.length());
                    continue;
                }

                // skip whitespace
                int skippedWhitespace = mSkipMatcher.match(begin, end, tokens).length();
                curIndex += skippedWhitespace;
                curColumn += skippedWhitespace;
                std::advance(begin, skippedWhitespace);

                // collect unmatched character
                if(!matched && skippedWhitespace == 0) {
                    if(!tokens.empty() && tokens.back().type() == dem::lexer::TokenType::UNKNOWN) {
                        Token &backToken = tokens.back();
                        backToken.setContent(backToken.content() + std::string(1, *begin));
                    } else {
                        tokens.push_back(Token(dem::lexer::TokenType::UNKNOWN, std::string(1, *begin), curIndex, curLine, curColumn));
                    }
                    ++begin;
                }
            }

            return tokens;
        }

        bool Lexer::match(std::vector<Token> &tokens, std::string::iterator &begin, std::string::iterator &end, int &curLine, int &curColumn, int &curIndex) const {
            for(TokenDefinition *tokenDefinition : mTokenDefinitions) {
                if(!tokenDefinition)
                    continue;

                std::string matched = tokenDefinition->matcher().match(begin, end, tokens);

                if(matched.length() > 0) {
                    std::advance(begin, matched.length());

                    if(!tokenDefinition->ignore())
                        tokens.push_back(Token(tokenDefinition->type(), matched, curIndex, curLine, curColumn));

                    curColumn += matched.length();
                    curIndex += matched.length();

                    return true;
                }
            }

            return false;
        }
    }
}

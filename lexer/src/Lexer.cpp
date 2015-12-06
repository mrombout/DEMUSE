#include <iostream>
#include <TokenPosition.h>
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
            TokenPosition tokenPosition;
            return lex(begin, end, tokenPosition);
        }

        std::vector<Token> Lexer::lex(std::string::iterator &begin, std::string::iterator &end, TokenPosition &tokenPosition) const {
            std::vector<Token> tokens;

            int currentTokenSize = 0;
            while(begin != end) {
                currentTokenSize = tokens.size();

                // should we stop?
                if(mStopMatcher && mStopMatcher->match(begin, end, tokens, tokenPosition).length() > 0)
                    return tokens;

                // match single token
                bool matched = match(tokens, begin, end, tokenPosition);

                // skip newlines
                std::string newLine;
                if((newLine = mNewLineMatcher.match(begin, end, tokens, tokenPosition)).length() > 0) {
                    tokenPosition.line += 1;
                    tokenPosition.index += newLine.size();
                    tokenPosition.column = 1;
                    std::advance(begin, newLine.length());
                    continue;
                }

                // skip whitespace
                int skippedWhitespace = mSkipMatcher.match(begin, end, tokens, tokenPosition).length();
                tokenPosition.index += skippedWhitespace;
                tokenPosition.column += skippedWhitespace;
                std::advance(begin, skippedWhitespace);

                // collect unmatched character
                if(!matched && skippedWhitespace == 0) {
                    // add new unknown token
                    tokens.push_back(Token(dem::lexer::TokenType::UNKNOWN, std::string(1, *begin), tokenPosition));
                    tokenPosition.index += 1;
                    ++begin;
                }

                // TODO: Below makes sure we're not stuck on an infinite loop, but below also breaks when there is no match but a newline (causing everything to stop).
                //if(tokens.size() == currentTokenSize)
                //    break;
            }

            return tokens;
        }

        bool Lexer::match(std::vector<Token> &tokens, std::string::iterator &begin, std::string::iterator &end, TokenPosition &tokenPosition) const {
            for(TokenDefinition *tokenDefinition : mTokenDefinitions) {
                if(!tokenDefinition)
                    continue;

                std::string matched = tokenDefinition->matcher().match(begin, end, tokens, tokenPosition);

                if(matched.length() > 0) {
                    std::advance(begin, matched.length());

                    if(!tokenDefinition->ignore())
                        tokens.push_back(Token(tokenDefinition->type(), matched, tokenPosition));

                    tokenPosition.column += matched.length();
                    tokenPosition.index += matched.length();

                    return true;
                }
            }

            return false;
        }
    }
}

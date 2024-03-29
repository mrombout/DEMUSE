#include <iostream>
#include <TokenPosition.h>
#include "Lexer.h"
#include "TokenType.h"

namespace dem {
    namespace lexer {
        Lexer::Lexer() :
            Lexer(nullptr) {

        }

        Lexer::Lexer(std::unique_ptr<Matcher> stopMatcher) :
            mSkipMatcher("\\s*"),
            mStopMatcher(std::move(stopMatcher)) {

        }

        void Lexer::addDefinition(std::unique_ptr<TokenDefinition> tokenDefinition) {
            mTokenDefinitions.push_back(std::move(tokenDefinition));
        }

        std::vector<Token> Lexer::lex(std::string::iterator &begin, std::string::iterator &end, bool ignore) const {
            TokenPosition tokenPosition;
            return lex(begin, end, ignore, tokenPosition);
        }

        std::vector<Token> Lexer::lex(std::string::iterator &begin, std::string::iterator &end, bool ignore, TokenPosition &tokenPosition) const {
            std::vector<Token> tokens;

            while(begin != end) {
                std::string::iterator startIterator = begin;

                // should we stop?
                if(mStopMatcher && mStopMatcher->match(begin, end, tokens, tokenPosition).length() > 0)
                    return tokens;

                // match single token
                bool matched = match(tokens, begin, end, ignore, tokenPosition);

                // skip newlines
                std::string newLine;
                if((newLine = mNewLineMatcher.match(begin, end, tokens, tokenPosition)).length() > 0) {
                    tokenPosition.line += 1;
                    tokenPosition.index += newLine.size();
                    tokenPosition.column = 1;
                    if(begin != end)
                        std::advance(begin, newLine.length());
                    continue;
                }

                // skip whitespace
                int skippedWhitespace = mSkipMatcher.match(begin, end, tokens, tokenPosition).length();
                tokenPosition.index += skippedWhitespace;
                tokenPosition.column += skippedWhitespace;
                if(begin != end)
                    std::advance(begin, skippedWhitespace);

                // collect unmatched character
                if(!matched && skippedWhitespace == 0) {
                    // TODO: Merge consecutive unknown tokens
                    // add new unknown token
                    tokens.push_back(Token(dem::lexer::TokenType::UNKNOWN, std::string(1, *begin), tokenPosition));
                    tokenPosition.index += 1;
                    ++begin;
                }

                if(startIterator == begin)
                    break;
            }

            tokens.push_back(Token(dem::lexer::TokenType::ENDOFFILE, "EOF", tokenPosition));

            return tokens;
        }

        bool Lexer::match(std::vector<Token> &tokens, std::string::iterator &begin, std::string::iterator &end, bool ignore, TokenPosition &tokenPosition) const {
            for(const std::unique_ptr<TokenDefinition> &tokenDefinition : mTokenDefinitions) {
                if(!tokenDefinition || begin == end)
                    continue;

                std::string matched = tokenDefinition->matcher().match(begin, end, tokens, tokenPosition);

                if(matched.length() > 0) {
                    if(begin != end)
                        std::advance(begin, matched.length());

                    if(!ignore || !tokenDefinition->ignore())
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

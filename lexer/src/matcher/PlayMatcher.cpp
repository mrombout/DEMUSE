#include "matcher/PlayMatcher.h"

namespace dem {
    namespace lexer {
        PlayMatcher::PlayMatcher() :
            mStartMatcher("<<") {

        }

        std::string dem::lexer::PlayMatcher::match(std::string::iterator &begin, std::string::iterator &end, std::vector<Token> &tokens, TokenPosition &tokenPosition) const {
            // find "<<"
            std::string startToken = mStartMatcher.match(begin, end, tokens, tokenPosition);
            if(startToken == "")
                return "";
            std::advance(begin, startToken.length());
            tokens.push_back(Token(TokenType::PLAY_START, startToken, tokenPosition));
            tokenPosition.column += startToken.size();
            tokenPosition.index += startToken.size();

            std::vector<Token> playTokens = mLexer.lex(begin, end, true, tokenPosition);
            for (Token &token : playTokens) {
                tokens.push_back(token);
            }

            return ">>";
        }
    }
}
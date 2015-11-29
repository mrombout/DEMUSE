#include "matcher/PlayMatcher.h"

namespace dem {
    namespace lexer {
        PlayMatcher::PlayMatcher() :
            mStartMatcher("<<") {

        }

        std::string dem::lexer::PlayMatcher::match(std::string::iterator &begin, std::string::iterator &end,
                                                   std::vector<Token> &tokens) const {
            // find "<<"
            std::string startToken = mStartMatcher.match(begin, end, tokens);
            if(startToken == "")
                return "";
            std::advance(begin, startToken.length());
            tokens.push_back(Token(TokenType::PLAY_START, startToken, 0, 0, 0));

            std::vector<Token> playTokens = mLexer.lex(begin, end);
            for (Token &token : playTokens) {
                tokens.push_back(token);
            }

            return ">>";
        }
    }
}
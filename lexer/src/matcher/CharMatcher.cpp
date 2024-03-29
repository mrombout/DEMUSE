#include "matcher/CharMatcher.h"

namespace dem {
    namespace lexer {
        CharMatcher::CharMatcher(char c) :
                mChar(c) {

        }

        std::string CharMatcher::match(std::string::iterator &begin, std::string::iterator &end, std::vector<Token> &tokens, TokenPosition &tokenPosition) const {
            return (*begin) == mChar ? std::string(1, mChar) : "";
        }
    }
}

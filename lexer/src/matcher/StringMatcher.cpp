#include <string>
#include "matcher/StringMatcher.h"

namespace dem {
    namespace lexer {
        StringMatcher::StringMatcher(std::string contents) :
            mContent(contents) {

        }

        std::string StringMatcher::match(std::string::iterator &begin, std::string::iterator &end, std::vector<Token> &tokens, TokenPosition &tokenPosition) const {
            std::string::iterator newBegin = begin;

            for(char c : mContent) {
                if(*newBegin != c)
                    return "";
                newBegin++;
            }

            return mContent;
        }
    }
}

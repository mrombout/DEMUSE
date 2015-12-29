#include "matcher/SingleCommentMatcher.h"

namespace dem {
    namespace lexer {
        std::string SingleCommentMatcher::match(std::string::iterator &begin, std::string::iterator &end, std::vector<Token> &tokens, TokenPosition &tokenPosition) const {
            std::string::iterator newBegin = begin;
            std::string::iterator newEnd = end;
            std::string matchResult;

            // "//"
            for(int i = 0; i < 2; ++i) {
                if(*newBegin == '/') {
                    matchResult += *newBegin;
                    ++newBegin;
                }
            }
            if(matchResult != "//")
                return "";

            // match until newline
            while(mNewLineMatcher.match(newBegin, newEnd, tokens, tokenPosition).empty() && newBegin != newEnd) {
                matchResult += *newBegin;
                ++newBegin;
            }

            return matchResult;
        }
    }
}
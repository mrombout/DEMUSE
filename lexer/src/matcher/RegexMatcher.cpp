#include "matcher/RegexMatcher.h"

namespace dem {
    namespace lexer {
        RegexMatcher::RegexMatcher(std::string regex) :
            mRegex(std::regex("^(" + regex + ")")) {
        }

        std::string RegexMatcher::match(std::string::iterator begin, std::string::iterator end) const {
            std::match_results<std::string::iterator> match;
            if(std::regex_search<std::string::iterator>(begin, end, match, mRegex))
                return match[0];
            return "";
        }
    }
}

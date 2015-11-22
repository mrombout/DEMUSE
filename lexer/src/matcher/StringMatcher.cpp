#include <string>
#include "matcher/StringMatcher.h"

namespace dem {
    namespace lexer {
        StringMatcher::StringMatcher(std::string content) :
            mContent(content) {

        }

        std::string StringMatcher::match(std::string::iterator begin, std::string::iterator end, std::vector<Token> &tokens) const {
            std::string str{""};
            str.append(begin, begin + mContent.length());

            if(str == mContent)
                return mContent;
            return "";
        }
    }
}

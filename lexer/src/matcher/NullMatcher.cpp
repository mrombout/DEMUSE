#include "matcher/NullMatcher.h"

namespace dem {
    namespace lexer {
        NullMatcher::NullMatcher(std::string name) :
            mName(name) {

        }

        std::string NullMatcher::match(std::string::iterator &begin, std::string::iterator &end) const {
            return "";
        }
    }
}

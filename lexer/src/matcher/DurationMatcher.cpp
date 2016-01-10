#include "matcher/DurationMatcher.h"

namespace dem {
    namespace lexer {
        DurationMatcher::DurationMatcher() :
                RegexMatcher("(w|h|q|i|s|t|x|o|\\.)\\b") {

        }
    }
}

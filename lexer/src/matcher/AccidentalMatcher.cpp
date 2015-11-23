#include "matcher/AccidentalMatcher.h"

namespace dem {
    namespace lexer {
        AccidentalMatcher::AccidentalMatcher() :
                RegexMatcher("(#|b|n)\\b"){

        }
    }
}

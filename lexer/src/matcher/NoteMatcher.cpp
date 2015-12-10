#include "matcher/NoteMatcher.h"
#include "matcher/AccidentalMatcher.h"

namespace dem {
    namespace lexer {
        NoteMatcher::NoteMatcher() :
                RegexMatcher("C|D|E|F|G|A|B|R") {

        }
    }
}

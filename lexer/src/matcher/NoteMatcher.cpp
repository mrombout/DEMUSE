#include "matcher/NoteMatcher.h"
#include "matcher/AccidentalMatcher.h"

namespace dem {
    namespace lexer {
        NoteMatcher::NoteMatcher(AccidentalMatcher *accidentalMatcher) :
                RegexMatcher("(C|D|E|F|G|A|B|R)(?=" + accidentalMatcher->regex() + "|;)") {

        }
    }
}

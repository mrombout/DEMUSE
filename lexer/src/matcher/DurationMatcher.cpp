#include "matcher/DurationMatcher.h"

namespace dem {
    namespace lexer {
        /**
         * Matches the duration of a note.
         *
         * Can be one of:
         *  - (w)hole
         *  - (h)alf
         *  - (q)uarter
         *  - e(i)ghth
         *  - (s)ixteenth
         *  - (t)hirty-second
         *  - si(x)ty-fourth
         *  - (o)ne-twenty-eighth
         *  - dotted (.)
         */
        DurationMatcher::DurationMatcher() :
                RegexMatcher("(w|h|q|i|s|t|x|o|\\.)\\b") {

        }
    }
}

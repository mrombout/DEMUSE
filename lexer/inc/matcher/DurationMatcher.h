#ifndef DEMUSE_DURATIONMATCHER_H
#define DEMUSE_DURATIONMATCHER_H

#include "RegexMatcher.h"

namespace dem {
    namespace lexer {
        /**
         * \brief Matches the duration of a note.
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
        class DurationMatcher : public RegexMatcher {
        public:
            DurationMatcher();
        };
    }
}

#endif //DEMUSE_DURATIONMATCHER_H

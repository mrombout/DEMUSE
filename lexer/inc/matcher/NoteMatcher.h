#ifndef DEMUSE_NOTEMATCHER_H
#define DEMUSE_NOTEMATCHER_H

#include "RegexMatcher.h"

namespace dem {
    namespace lexer {
        class AccidentalMatcher;
    }
}

namespace dem {
    namespace lexer {
        /**
         * \brief Matches a single note(A to G) or rest (R) note.
         */
        class NoteMatcher : public RegexMatcher {
        public:
            NoteMatcher();
        };
    }
}

#endif //DEMUSE_NOTEMATCHER_H

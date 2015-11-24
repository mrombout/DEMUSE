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
        class NoteMatcher : public RegexMatcher {
        public:
            NoteMatcher(AccidentalMatcher *accidentalMatcher);
        };
    }
}

#endif //DEMUSE_NOTEMATCHER_H

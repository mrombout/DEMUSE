#ifndef DEMUSE_ACCIDENTALMATCHER_H
#define DEMUSE_ACCIDENTALMATCHER_H

#include "RegexMatcher.h"
#include "NoteMatcher.h"

namespace dem {
    namespace lexer {
        class AccidentalMatcher : public RegexMatcher {
        public:
            AccidentalMatcher();
        };
    }
}

#endif //DEMUSE_ACCIDENTALMATCHER_H

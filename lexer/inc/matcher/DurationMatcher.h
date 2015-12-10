#ifndef DEMUSE_DURATIONMATCHER_H
#define DEMUSE_DURATIONMATCHER_H

#include "RegexMatcher.h"

namespace dem {
    namespace lexer {
        class DurationMatcher : public RegexMatcher {
        public:
            DurationMatcher();
        };
    }
}

#endif //DEMUSE_DURATIONMATCHER_H

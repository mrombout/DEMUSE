#ifndef DEMUSE_OCTAVEMATCHER_H
#define DEMUSE_OCTAVEMATCHER_H

#include "RegexMatcher.h"

namespace dem {
    namespace lexer {
        /**
         * \brief Matches an octave, ranging from 0 to 10.
         */
        class OctaveMatcher : public RegexMatcher {
        public:
            OctaveMatcher();
        };
    }
}


#endif //DEMUSE_OCTAVEMATCHER_H

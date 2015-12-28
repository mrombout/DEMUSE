#include "matcher/OctaveMatcher.h"

namespace dem {
    namespace lexer {
        OctaveMatcher::OctaveMatcher() :
                RegexMatcher("(10|[0-9])(?:^])") {

        }
    }
}

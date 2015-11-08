#ifndef DEMUSE_NULLMATCHER_H
#define DEMUSE_NULLMATCHER_H

#include "Matcher.h"

namespace dem {
    namespace lexer {
        class NullMatcher : public Matcher {
        public:
            NullMatcher(std::string name);

            virtual std::string match(std::string::iterator begin, std::string::iterator end) const;
        };
    }
}

#endif //DEMUSE_NULLMATCHER_H
#ifndef DEMUSE_CHARMATCHER_H
#define DEMUSE_CHARMATCHER_H

#include <string>
#include "Matcher.h"

namespace dem {
    namespace lexer {
        class CharMatcher : public Matcher {
        public:
            CharMatcher(char c);

            virtual std::string match(std::string::iterator &begin, std::string::iterator &end) const;

        private:
            char mChar;
        };
    }
}


#endif //DEMUSE_CHARMATCHER_H

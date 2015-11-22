#ifndef DEMUSE_PLAYMATCHER_H
#define DEMUSE_PLAYMATCHER_H

#include <string>
#include "matcher/Matcher.h"

namespace dem {
    namespace lexer {
        class PlayMatcher : public Matcher {

        public:
            virtual std::string match(std::string::iterator begin, std::string::iterator end, std::vector<Token> &tokens) const;
        };
    }
}

#endif //DEMUSE_PLAYMATCHER_H

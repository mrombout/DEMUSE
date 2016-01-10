#ifndef DEMUSE_MATCHER_H
#define DEMUSE_MATCHER_H

#include <vector>
#include <string>
#include "Token.h"
#include "TokenPosition.h"

namespace dem {
    namespace lexer {
        class Matcher {
        public:
            /**
             * \brief Matches as much as it can and returns the matched string.
             *
             * \note A matcher should not move the begin and end iterators or tokenPosition for the string returned.
             */
            virtual std::string match(std::string::iterator &begin, std::string::iterator &end, std::vector<Token> &tokens, TokenPosition &tokenPosition) const = 0;
        };
    }
}

#endif //DEMUSE_MATCHER_H

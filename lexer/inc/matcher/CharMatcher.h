#ifndef DEMUSE_CHARMATCHER_H
#define DEMUSE_CHARMATCHER_H

#include <string>
#include "Matcher.h"

namespace dem {
    namespace lexer {
        /**
         * \brief Matches a single character.
         */
        class CharMatcher : public Matcher {
        public:
            CharMatcher(char c);

            virtual std::string match(std::string::iterator &begin, std::string::iterator &end, std::vector<Token> &tokens, TokenPosition &tokenPosition) const;

        private:
            char mChar;
        };
    }
}


#endif //DEMUSE_CHARMATCHER_H

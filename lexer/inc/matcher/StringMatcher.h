#ifndef DEMUSE_STRINGMATCHER_H
#define DEMUSE_STRINGMATCHER_H

#include "Matcher.h"

namespace dem {
    namespace lexer {
        /**
         * \brief Matches a string of characters.
         */
        class StringMatcher : public Matcher {
        public:
            StringMatcher(std::string content);

            virtual std::string match(std::string::iterator &begin, std::string::iterator &end, std::vector<Token> &tokens, TokenPosition &tokenPosition) const;

        private:
            std::string mContent;
        };
    }
}

#endif //DEMUSE_STRINGMATCHER_H

#ifndef DEMUSE_NULLMATCHER_H
#define DEMUSE_NULLMATCHER_H

#include "Matcher.h"

namespace dem {
    namespace lexer {
        /**
         * \brief Never matches anything.
         */
        class NullMatcher : public Matcher {
        public:
            NullMatcher();

            virtual std::string match(std::string::iterator &begin, std::string::iterator &end, std::vector<Token> &tokens, TokenPosition &tokenPosition) const;
        };
    }
}

#endif //DEMUSE_NULLMATCHER_H

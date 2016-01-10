#ifndef DEMUSE_NEWLINEMATCHER_H
#define DEMUSE_NEWLINEMATCHER_H

#include "Matcher.h"

namespace dem {
    namespace lexer {
        /**
         * \brief Matches a newline character for both standard Windows and UNIX style newlines.
         */
        class NewLineMatcher : public Matcher {
        public:
            virtual std::string match(std::string::iterator &begin, std::string::iterator &end, std::vector<Token> &tokens, TokenPosition &tokenPosition) const;
        };
    }
}

#endif //DEMUSE_NEWLINEMATCHER_H

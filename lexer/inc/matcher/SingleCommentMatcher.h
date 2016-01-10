#ifndef DEMUSE_SINGLECOMMENTMATCHER_H
#define DEMUSE_SINGLECOMMENTMATCHER_H

#include "Matcher.h"
#include "matcher/NewLineMatcher.h"

namespace dem {
    namespace lexer {
        /**
         * \brief Matches a single line comments.
         *
         * It matches "//" and everything after than until a newline character is found. The newline is also included.
         */
        class SingleCommentMatcher : public Matcher {
        public:
            virtual std::string match(std::string::iterator &begin, std::string::iterator &end, std::vector<Token> &tokens, TokenPosition &tokenPosition) const;

        private:
            NewLineMatcher mNewLineMatcher;
        };
    }
}

#endif //DEMUSE_SINGLECOMMENTMATCHER_H

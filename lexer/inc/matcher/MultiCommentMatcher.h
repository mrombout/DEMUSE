#ifndef DEMUSE_MULTICOMMENTMATCHER_H
#define DEMUSE_MULTICOMMENTMATCHER_H

#include "Matcher.h"

namespace dem {
    namespace lexer {
        /**
         * \brief Matches comments over multiple lines. Matches everything between (and including) "/*" and "* /".
         */
        class MultiCommentMatcher : public Matcher {
        public:
            virtual std::string match(std::string::iterator &begin, std::string::iterator &end, std::vector<Token> &tokens, TokenPosition &tokenPosition) const;

        private:
            /**
             * \brief Matches the the open tag for a multi comment, "/*".
             */
            bool matchOpen(std::string::iterator &begin, std::string::iterator &end) const;

            /**
             * \brief Matches the the closing tag for a multi comment, "* /".
             */
            bool matchClose(std::string::iterator begin, std::string::iterator end) const;
        };
    }
}

#endif //DEMUSE_MULTICOMMENTMATCHER_H

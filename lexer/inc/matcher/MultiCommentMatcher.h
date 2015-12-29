#ifndef DEMUSE_MULTICOMMENTMATCHER_H
#define DEMUSE_MULTICOMMENTMATCHER_H

#include "Matcher.h"

namespace dem {
    namespace lexer {
        class MultiCommentMatcher : public Matcher {
        public:
            virtual std::string match(std::string::iterator &begin, std::string::iterator &end, std::vector<Token> &tokens, TokenPosition &tokenPosition) const;

            bool matchOpen(std::string::iterator &begin, std::string::iterator &end) const;
            bool matchClose(std::string::iterator begin, std::string::iterator end) const;
        };
    }
}

#endif //DEMUSE_MULTICOMMENTMATCHER_H

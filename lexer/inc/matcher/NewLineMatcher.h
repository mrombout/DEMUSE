#ifndef DEMUSE_NEWLINEMATCHER_H
#define DEMUSE_NEWLINEMATCHER_H

#include "Matcher.h"

namespace dem {
    namespace lexer {
        class NewLineMatcher : public Matcher {
        public:
            virtual std::string match(std::string::iterator &begin, std::string::iterator &end, std::vector<Token> &tokens, TokenPosition &tokenPosition) const;
        };
    }
}

#endif //DEMUSE_NEWLINEMATCHER_H

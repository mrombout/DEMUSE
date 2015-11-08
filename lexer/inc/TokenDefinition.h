#ifndef DEMUSE_TOKENDEFINITION_H
#define DEMUSE_TOKENDEFINITION_H

#include "matcher/Matcher.h"
#include "TokenType.h"

namespace dem {
    namespace lexer {
        struct TokenDefinition {
        public:
            TokenDefinition(TokenType tokenType, Matcher *matcher);
            ~TokenDefinition();

            TokenDefinition(const TokenDefinition &other);
            TokenDefinition & operator=(const TokenDefinition &other);

            TokenDefinition(TokenDefinition &&other);
            TokenDefinition &operator=(TokenDefinition &&other);

            const Matcher &matcher() const;
            const TokenType &type() const;

        public:
            Matcher *mMatcher;
            TokenType mTokenType;
        };
    }
}

#endif //DEMUSE_TOKENDEFINITION_H

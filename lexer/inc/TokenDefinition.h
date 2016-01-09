#ifndef DEMUSE_TOKENDEFINITION_H
#define DEMUSE_TOKENDEFINITION_H

#include <memory>
#include "matcher/Matcher.h"
#include "TokenType.h"

namespace dem {
    namespace lexer {
        struct TokenDefinition {
        public:
            TokenDefinition(const TokenType &tokenType, std::unique_ptr<Matcher> matcher, bool ignore = false);

            const Matcher &matcher() const;
            const TokenType &type() const;
            const bool &ignore() const;

        public:
            std::unique_ptr<Matcher> mMatcher;
            TokenType mTokenType;
            bool mIgnore;
        };
    }
}

#endif //DEMUSE_TOKENDEFINITION_H

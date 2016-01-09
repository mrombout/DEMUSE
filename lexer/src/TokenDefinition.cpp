#include "TokenDefinition.h"

namespace dem {
    namespace lexer {
        TokenDefinition::TokenDefinition(const TokenType &tokenType, std::unique_ptr<Matcher> matcher, bool ignore) :
            mMatcher(std::move(matcher)),
            mTokenType(tokenType),
            mIgnore(ignore) {

        }

        const TokenType &TokenDefinition::type() const {
            return mTokenType;
        }

        const Matcher &TokenDefinition::matcher() const {
            return *mMatcher;
        }

        const bool &TokenDefinition::ignore() const {
            return mIgnore;
        }
    }
}

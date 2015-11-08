#include "TokenDefinition.h"

namespace dem {
    namespace lexer {
        TokenDefinition::TokenDefinition(TokenType tokenType, Matcher *matcher) :
            mMatcher(matcher),
            mTokenType(tokenType) {

        }

        TokenDefinition::~TokenDefinition() {
            delete mMatcher;
        }

        TokenDefinition::TokenDefinition(const TokenDefinition &other) {
            mTokenType = other.mTokenType;

            if(other.mMatcher) {
                *mMatcher = *other.mMatcher;
            }
        }

        TokenDefinition &TokenDefinition::operator=(const TokenDefinition &other) {
            if(this == &other)
                return *this;

            delete mMatcher;

            mTokenType = other.mTokenType;

            if(mMatcher) {
                *mMatcher = *other.mMatcher;
            }

            return *this;
        }

        TokenDefinition::TokenDefinition(TokenDefinition &&other) {
            mTokenType = other.mTokenType;
            mMatcher = other.mMatcher;

            other.mMatcher = nullptr;
        }

        TokenDefinition &TokenDefinition::operator=(TokenDefinition &&other) {
            if(this == &other)
                return *this;

            mTokenType = other.mTokenType;
            mMatcher = other.mMatcher;

            other.mMatcher = nullptr;

            return *this;
        }

        const TokenType &TokenDefinition::type() const {
            return mTokenType;
        }

        const Matcher &TokenDefinition::matcher() const {
            return *mMatcher;
        }
    }
}

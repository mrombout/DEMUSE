#include "TokenDefinition.h"

namespace dem {
    namespace lexer {
        TokenDefinition::TokenDefinition(const TokenType &tokenType, Matcher *matcher, bool ignore) :
            mMatcher(matcher),
            mTokenType(tokenType),
            mIgnore(ignore) {

        }

        TokenDefinition::~TokenDefinition() {
            delete mMatcher;
        }

        TokenDefinition::TokenDefinition(const TokenDefinition &other) {
            std::cout << "copy-constructor" << std::endl;
            mTokenType = other.mTokenType;

            if(other.mMatcher) {
                *mMatcher = *other.mMatcher;
            }
        }

        TokenDefinition &TokenDefinition::operator=(const TokenDefinition &other) {
            std::cout << "copy-assignment" << std::endl;
            if(this == &other)
                return *this;

            delete mMatcher;

            //mTokenType = other.mTokenType;
            mTokenType = TokenType::ASSIGNMENT;

            if(mMatcher) {
                *mMatcher = *other.mMatcher;
            }

            return *this;
        }

        TokenDefinition::TokenDefinition(TokenDefinition &&other) {
            std::cout << "move-constructor" << std::endl;
            //mTokenType = other.mTokenType;
            mTokenType = TokenType::ASSIGNMENT;
            mMatcher = other.mMatcher;

            other.mMatcher = nullptr;
        }

        TokenDefinition &TokenDefinition::operator=(TokenDefinition &&other) {
            std::cout << "move-assignment" << std::endl;
            if(this == &other)
                return *this;

            //mTokenType = other.mTokenType;
            mTokenType = TokenType::ASSIGNMENT;
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

        const bool &TokenDefinition::ignore() const {
            return mIgnore;
        }
    }
}

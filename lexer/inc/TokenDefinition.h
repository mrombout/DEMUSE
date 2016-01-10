#ifndef DEMUSE_TOKENDEFINITION_H
#define DEMUSE_TOKENDEFINITION_H

#include <memory>
#include "matcher/Matcher.h"
#include "TokenType.h"

namespace dem {
    namespace lexer {
        /**
         * \brief A token definition maps a token type with a matcher than can be used with the lexer.
         *
         * A token definition can be set to be ignored by the lexer. When a token definition is ignored the token type
         * is not added to the list when matched. This can be useful for things like comments.
         */
        struct TokenDefinition {
        public:
            /**
             * \brief Constructs a new TokenDefinition.
             *
             * \param tokenType the type of the token
             * \param matcher   the matcher to use
             * \param ignore    whether to ignore this token (ignored tokens are not added to the token list)
             */
            TokenDefinition(const TokenType &tokenType, std::unique_ptr<Matcher> matcher, bool ignore = false);

            /**
             * \brief Returns the matcher of this definition.
             *
             * \return matcher of this definition
             */
            const Matcher &matcher() const;

            /**
             * \brief Returns the type of this definition.
             *
             * \return type of this definition
             */
            const TokenType &type() const;

            /**
             * \brief Returns whether this tokendefinition is ignored by the lexer.
             *
             * \return whether this token is ignored by the lexer, ignored token definition are not added to the list
             */
            const bool &ignore() const;

        public:
            std::unique_ptr<Matcher> mMatcher;
            TokenType mTokenType;
            bool mIgnore;
        };
    }
}

#endif //DEMUSE_TOKENDEFINITION_H

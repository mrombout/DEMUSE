#ifndef DEMUSE_TOKENIZER_H
#define DEMUSE_TOKENIZER_H

#include <string>
#include <vector>
#include "matcher/NewLineMatcher.h"
#include "matcher/RegexMatcher.h"
#include "Token.h"
#include "TokenDefinition.h"
#include "TokenPosition.h"

namespace dem {
    namespace lexer {
        /**
         * Lexes a string by building a list of Tokens according to the set list of token definitions. When the matcher
         * of a token definitions matches the associated token is added to the list.
         */
        class Lexer {
        public:
            /**
             * \brief Constructs a new lexer.
             */
            Lexer();

            /**
             * \brief Constructs a new lexer that uses a stop matcher.
             *
             * @param stopMatcher when this matcher matches, the lexer will stop lexing and return the current token list
             */
            Lexer(std::unique_ptr<Matcher> stopMatcher);

            /**
             * \brief Adds a new token definition to this lexer.
             *
             * A token definition determines which tokens this lexer is able to match.
             */
            void addDefinition(std::unique_ptr<TokenDefinition> tokenDefinition);

            /**
             * \brief Starts lexing the given input.
             *
             * \param ignore whether ignored token definitions should be ignored (when ignore is false, token definitions will *always* be added to the list)
             * \return a list of matched tokens
             */
            std::vector<Token> lex(std::string::iterator &begin, std::string::iterator &end, bool ignore = true) const;

            /**
             * \brief Starts lexing the given input.
             *
             * \param ignore whether ignored token definitions should be ignored (when ignore is false, token definitions will *always* be added to the list)
             * \param tokenPosition token position to use as a start position.
             * \return a list of matched tokens
             */
            std::vector<Token> lex(std::string::iterator &begin, std::string::iterator &end, bool ignore, TokenPosition &tokenPosition) const;

        private:
            bool match(std::vector<Token> &tokens, std::string::iterator &begin, std::string::iterator &end, bool ignore, TokenPosition &tokenPosition) const;

        private:
            std::vector<std::unique_ptr<TokenDefinition>> mTokenDefinitions;

            std::unique_ptr<Matcher> mStopMatcher;
            NewLineMatcher mNewLineMatcher;
            RegexMatcher mSkipMatcher;
        };
    }
}

#endif //DEMUSE_TOKENIZER_H

#ifndef DEMUSE_SYMBOLFACTORY_H
#define DEMUSE_SYMBOLFACTORY_H

#include <deque>
#include "Token.h"
#include "TokenType.h"
#include "Parser.h"

namespace dem {
    namespace parser {
        /**
         * \brief Provides several utility functions for symbol factories.
         */
        class SymbolFactory {
        protected:
            /**
             * \brief Accepts a token and throws an exception if token can not be accepted
             *
             * Accepts (see ::accept) a token and returns true when the token is ssuccessfullyaccepted. If the token is
             * not accepted an error is added to the given ParseResults.
             *
             * \param tokens    tokens to check, the first (front) token is checked
             * \param tokenType token type to compare to
             * \param results   results to add the error to when an error is found
             * \param pop       whether to pop the token of the stack, defaults to true
             * \returns whether the token has been found
             */
            static bool expect(std::deque<lexer::Token> &tokens, lexer::TokenType tokenType, ParseResults &results, bool pop = true);

            /**
             * \briefs Accepts a token by comparing the type with the given tokenType and pops it of the stack if found
             *
             * Accepts a token by comparing the given tokenType with the type of the token at the front of the given
             * tokens deque. Returns true if this token has the given tokenType, false otherwise.
             *
             * \param tokens    tokens to check, the first (front) token is checked
             * \param tokenType token type to compare to
             * \param pop       whether to pop the token of the stack, defaults to true
             * \returns whether the token has been found
             */
            static bool accept(std::deque<lexer::Token> &tokens, lexer::TokenType tokenType, bool pop = true);

            /**
             * \brief Adds an error to the given ParseResults.
             *
             * \param results     results to add the error to
             * \param token       token at which the error occured
             * \param description clear description of the error
             */
            static void addError(ParseResults &results, lexer::Token token, const std::string &description);

            /**
             * \brief Adds a warning to the given ParseResults.
             *
             * \param results     results to add the warning to
             * \param token       token at which the warning occured
             * \param description clear description of the warning
             */
            static void addWarning(ParseResults &results, lexer::Token token, const std::string &description);

            /**
             * \brief Adds an error to the given ParseReults of the given type.
             *
             * \param type        type of the error
             * \param results     results to add the warning to
             * \param token       token at which the warning occured
             * \param description clear description of the warning
             */
            static void addError(ParseError::Type type, ParseResults &results, lexer::Token token, const std::string &description);
        };
    }
}

#endif //DEMUSE_SYMBOLFACTORY_H

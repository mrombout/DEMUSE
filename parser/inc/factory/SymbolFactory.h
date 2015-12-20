#ifndef DEMUSE_SYMBOLFACTORY_H
#define DEMUSE_SYMBOLFACTORY_H

#include <deque>
#include "Token.h"
#include "TokenType.h"
#include "Parser.h"

namespace dem {
    namespace parser {
        class SymbolFactory {
        protected:
            static bool expect(std::deque<lexer::Token> &tokens, lexer::TokenType tokenType, ParseResults &results, bool pop = true);
            static bool accept(std::deque<lexer::Token> &tokens, lexer::TokenType tokenType, bool pop = true);

            static void addError(ParseResults &results, lexer::Token token, const std::string &description);
            static void addWarning(ParseResults &results, lexer::Token token, const std::string &description);
            static void addError(ParseError::Type type, ParseResults &results, lexer::Token token, const std::string &description);
        };
    }
}

#endif //DEMUSE_SYMBOLFACTORY_H

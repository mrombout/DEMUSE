#ifndef DEMUSE_SYMBOLFACTORY_H
#define DEMUSE_SYMBOLFACTORY_H

#include <deque>
#include "Token.h"
#include "TokenType.h"

namespace dem {
    namespace parser {
        class SymbolFactory {
        protected:
            static bool expect(std::deque<lexer::Token> &tokens, lexer::TokenType &tokenType);
            static bool accept(std::deque<lexer::Token> &tokens, lexer::TokenType &tokenType);
        };
    }
}

#endif //DEMUSE_SYMBOLFACTORY_H

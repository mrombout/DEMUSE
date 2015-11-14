#include "factory/SymbolFactory.h"

namespace dem {
    namespace parser {
        bool SymbolFactory::expect(std::deque<lexer::Token> &tokens, lexer::TokenType tokenType) {
            if(accept(tokens, tokenType))
                return true;
            throw "TODO: Some proper error";
        }

        bool SymbolFactory::accept(std::deque<lexer::Token> &tokens, lexer::TokenType tokenType) {
            if(tokens.front().is(tokenType)) {
                tokens.pop_front();
                return true;
            }
            return false;
        }
    }
}

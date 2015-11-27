#include "factory/SymbolFactory.h"
#include "exception/ParsingException.h"

namespace dem {
    namespace parser {
        bool SymbolFactory::expect(std::deque<lexer::Token> &tokens, lexer::TokenType tokenType) {
            if(accept(tokens, tokenType))
                return true;
            if(tokens.empty())
                throw ParsingException();
            std::cout << "Crashing on " << tokens.front().type() << ", expected " << tokenType << std::endl;
            throw ParsingException(tokens.front());
            // TODO: Proper messages
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

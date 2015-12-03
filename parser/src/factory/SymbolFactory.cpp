#include <sstream>
#include "factory/SymbolFactory.h"
#include "exception/ParsingException.h"

namespace dem {
    namespace parser {
        bool SymbolFactory::expect(std::deque<lexer::Token> &tokens, lexer::TokenType tokenType, bool pop) {
            if(accept(tokens, tokenType, pop))
                return true;

            std::stringstream ss;
            if(tokens.empty()) {
                ss << "Expected '" << tokenType << "', but found nothing.";
                //throw ParsingException(ss.str());
            }

            ss << "Expected '" << tokenType << "', but found " << tokens.front().type();
            throw ParsingException(tokens.front(), ss.str());
        }

        bool SymbolFactory::accept(std::deque<lexer::Token> &tokens, lexer::TokenType tokenType, bool pop) {
            if(tokens.front().is(tokenType)) {
                if(pop)
                    tokens.pop_front();
                return true;
            }
            return false;
        }
    }
}

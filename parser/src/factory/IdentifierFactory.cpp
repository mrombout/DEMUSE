#include "factory/IdentifierFactory.h"

namespace dem {
    namespace parser {
        Identifier *IdentifierFactory::produce(std::deque<lexer::Token> &tokens) {
            // identifier = letter { letter | number }

            // letter { letter | number }
            lexer::Token token = tokens.front();
            expect(tokens, lexer::TokenType::IDENTIFIER);

            return new Identifier(token.content());
        }
    }
}

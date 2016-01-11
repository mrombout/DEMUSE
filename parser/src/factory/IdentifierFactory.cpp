#include "factory/IdentifierFactory.h"
#include "symbol/Identifier.h"

namespace dem {
    namespace parser {
        Identifier *IdentifierFactory::produce(std::deque<lexer::Token> &tokens, ParseResults &results) {
            // identifier = letter { letter | number }

            // letter { letter | number }
            lexer::Token token = tokens.front();
            expect(tokens, lexer::TokenType::IDENTIFIER, results);

            std::clog << "[CREATE] Identifier" << std::endl;
            return new Identifier(token, token.content());
        }
    }
}

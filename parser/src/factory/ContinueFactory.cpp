#include "factory/ContinueFactory.h"
#include "symbol/Continue.h"

namespace dem {
    namespace parser {
        Continue *ContinueFactory::produce(std::deque<lexer::Token> &tokens, ParseResults &results) {
            // continue_stmt = "continue" ;

            // "continue"
            expect(tokens, lexer::TokenType::CONTINUE, results);

            return new Continue();
        }
    }
}

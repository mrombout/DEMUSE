#include "factory/ContinueFactory.h"

namespace dem {
    namespace parser {
        Continue *ContinueFactory::produce(std::deque<lexer::Token> &tokens) {
            // continue_stmt = "continue" ;

            // "continue"
            expect(tokens, lexer::TokenType::CONTINUE);

            return new Continue();
        }
    }
}

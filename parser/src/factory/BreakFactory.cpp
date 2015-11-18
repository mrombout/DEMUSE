#include "factory/BreakFactory.h"
#include "symbol/Break.h"

namespace dem {
    namespace parser {
        Break *dem::parser::BreakFactory::produce(std::deque<lexer::Token> &tokens) {
            // break_stmt = "break" ;

            // "break"
            expect(tokens, lexer::TokenType::BREAK);

            return new Break();
        }
    }
}

#include "factory/BreakFactory.h"

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

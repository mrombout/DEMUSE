#include "factory/BreakFactory.h"
#include "symbol/Break.h"

namespace dem {
    namespace parser {
        Break *dem::parser::BreakFactory::produce(std::deque<lexer::Token> &tokens, ParseResults &results) {
            // break_stmt = "break" ;

            // "break"
            lexer::Token token = tokens.front();
            expect(tokens, lexer::TokenType::BREAK, results);

            return new Break(token);
        }
    }
}

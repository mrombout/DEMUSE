#include <factory/ExpressionFactory.h>
#include "factory/InstrumentFactory.h"

namespace dem {
    namespace parser {
        Instrument *InstrumentFactory::produce(std::deque<lexer::Token> &tokens, ParseResults &results) {
            // instrument = "I[" ( number | identifier ) "]"

            // "I"
            expect(tokens, lexer::TokenType::INSTRUMENT, results);

            // "["
            expect(tokens, lexer::TokenType::BRACKET_OPEN, results);

            // note | identifier
            Expression *expression = ExpressionFactory::produce(tokens, results);

            // "]"
            expect(tokens, lexer::TokenType::BRACKET_CLOSE, results);

            return new Instrument(expression);
        }
    }
}

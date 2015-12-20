#include "factory/ExpressionFactory.h"
#include "factory/ReturnFactory.h"
#include "symbol/expression/Expression.h"
#include "symbol/Return.h"

namespace dem {
    namespace parser {
        Return *ReturnFactory::produce(std::deque<lexer::Token> &tokens, ParseResults &results) {
            // return_stmt = "return" expression

            // "return"
            expect(tokens, lexer::TokenType::RETURN, results);

            // expression
            Expression *expression = ExpressionFactory::produce(tokens, results);

            return new Return(expression);
        }
    }
}

#include "symbol/Expression.h"
#include "factory/ExpressionFactory.h"
#include "factory/ReturnFactory.h"

namespace dem {
    namespace parser {
        Return *ReturnFactory::produce(std::deque<lexer::Token> tokens) {
            // return_stmt = "return" expression

            // "return"
            expect(tokens, lexer::TokenType::RETURN);

            // expression
            Expression *expression = ExpressionFactory::produce(tokens);

            return new Return(expression);
        }
    }
}

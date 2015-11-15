#include <vector>
#include "factory/ArgumentListFactory.h"
#include "factory/ExpressionFactory.h"
#include "symbol/Expression.h"

namespace dem {
    namespace parser {
        ArgumentList *ArgumentListFactory::produce(std::deque<lexer::Token> &tokens) {
            // argument_list = expression | argument_list "," expression ;

            std::vector<Expression*> expressions;

            // expression
            Expression *expression = ExpressionFactory::produce(tokens);
            expressions.push_back(expression);

            // "," expression
            while(accept(tokens, lexer::TokenType::COMMA)) {
                expressions.push_back(ExpressionFactory::produce(tokens));
            }

            return new ArgumentList(expressions);
        }
    }
}

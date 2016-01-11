#include <vector>
#include "factory/ArgumentListFactory.h"
#include "factory/ExpressionFactory.h"
#include "symbol/expression/Expression.h"
#include "symbol/ArgumentList.h"

namespace dem {
    namespace parser {
        ArgumentList *ArgumentListFactory::produce(std::deque<lexer::Token> &tokens, ParseResults &results) {
            // argument_list = expression | argument_list "," expression ;

            lexer::Token token = tokens.front();
            std::vector<Expression*> expressions;

            // expression
            Expression *expression = ExpressionFactory::produce(tokens, results);
            expressions.push_back(expression);

            // "," expression
            while(accept(tokens, lexer::TokenType::COMMA)) {
                expressions.push_back(ExpressionFactory::produce(tokens, results));
            }

            return new ArgumentList(token, expressions);
        }
    }
}

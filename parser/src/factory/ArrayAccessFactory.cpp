#include <factory/ExpressionFactory.h>
#include "factory/ArrayAccessFactory.h"

namespace dem {
    namespace parser {
        ArrayAccessExpression *ArrayAccessFactory::produce(std::deque<lexer::Token> &tokens, Expression *lvalue) {
            // array_access = identifier "[" ( primary ) "]" ;

            if(tokens.front().is(lexer::TokenType::BRACKET_OPEN)) {
                ArrayAccessExpression *arrayAccessExpression = nullptr;
                while(accept(tokens, lexer::TokenType::BRACKET_OPEN)) {
                    Expression *arrayIndex = ExpressionFactory::produce(tokens);
                    expect(tokens, lexer::TokenType::BRACKET_CLOSE);

                    if(!arrayAccessExpression)
                        arrayAccessExpression = new ArrayAccessExpression(lvalue, arrayIndex);
                    else
                        arrayAccessExpression = new ArrayAccessExpression(arrayAccessExpression, arrayIndex);
                }

                return arrayAccessExpression;
            }
        }
    }
}

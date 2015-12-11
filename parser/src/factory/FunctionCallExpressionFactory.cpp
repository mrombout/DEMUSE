#include "factory/FunctionCallExpressionFactory.h"
#include "factory/IdentifierFactory.h"
#include "factory/ArgumentListFactory.h"
#include "symbol/expression/FunctionCallExpression.h"

namespace dem {
    namespace parser {
        FunctionCallExpression *FunctionCallExpressionFactory::produce(std::deque <lexer::Token> &tokens, Expression *expression) {
            // identifier "(" [ argument_list ] ")" ;

            // "("
            expect(tokens, lexer::TokenType::OPEN);

            // [ argument_list ]
            ArgumentList *argumentList = new parser::ArgumentList(std::vector<Expression*>());
            if(!tokens.front().is(lexer::TokenType::CLOSE)) {
                argumentList = ArgumentListFactory::produce(tokens);
            }

            // ")"
            expect(tokens, lexer::TokenType::CLOSE);

            std::cout << "[CREATE] FunctionCallExpression" << std::endl;
            return new FunctionCallExpression(argumentList, expression);
        }
    }
}
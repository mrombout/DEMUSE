#include <vector>
#include "symbol/expression/Expression.h"
#include "symbol/Block.h"
#include "factory/IfFactory.h"
#include "factory/ExpressionFactory.h"
#include "factory/BlockFactory.h"
#include "factory/StatementFactory.h"

namespace dem {
    namespace parser {
        If *IfFactory::produce(std::deque<lexer::Token> &tokens) {
            // if_stmt = "if(" conditional ")" block
            //              [ "else" ( block | statement ) ] ;

            // "if("
            expect(tokens, lexer::TokenType::IF);
            expect(tokens, lexer::TokenType::OPEN);

            // conditional
            Expression *expression = ExpressionFactory::produce(tokens);

            // ")"
            expect(tokens, lexer::TokenType::CLOSE);

            // block
            Block *block = BlockFactory::produce(tokens);

            // [ "else" ( block | statement ) ]
            if(accept(tokens, lexer::TokenType::ELSE)) {
                Block *elseBlock = nullptr;
                if(tokens.front().is(lexer::TokenType::START)) {
                    // block
                    elseBlock = BlockFactory::produce(tokens);
                } else {
                    // statement
                    Statement *statement = StatementFactory::produce(tokens);
                    std::vector<Statement*> statements{statement};

                    elseBlock = new Block(statements);
                }

                return new If(expression, block, elseBlock);
            }

            return new If(expression, block);
        }
    }
}

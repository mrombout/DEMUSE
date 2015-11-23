#include <vector>
#include "factory/IfFactory.h"
#include "factory/ExpressionFactory.h"
#include "factory/BlockFactory.h"
#include "factory/StatementFactory.h"
#include "symbol/expression/Expression.h"
#include "symbol/Block.h"
#include "symbol/If.h"

namespace dem {
    namespace parser {
        If *IfFactory::produce(std::deque<lexer::Token> &tokens) {
            // if_stmt = "if(" conditional ")" ( block | statement )
            //              [ "else" ( block | statement ) ] ;

            // "if("
            expect(tokens, lexer::TokenType::IF);
            expect(tokens, lexer::TokenType::OPEN);

            // conditional
            Expression *expression = ExpressionFactory::produce(tokens);
            // TODO: Can expression ever be nullptr? If so, check and throw exception

            // ")"
            expect(tokens, lexer::TokenType::CLOSE);

            // block | statement
            Block *block = nullptr;
            if(tokens.front().is(lexer::TokenType::START)) {
                // block
                block = BlockFactory::produce(tokens);
            } else {
                // statement
                Statement *statement = StatementFactory::produce(tokens);
                std::vector<Statement*> statements{statement};
                // TODO: Can statement every be nullptr? If so, check and throw exception

                block = new Block(statements);
            }

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
                    // TODO: Can statement every be nullptr? If so, check and throw exception

                    elseBlock = new Block(statements);
                }

                return new If(expression, block, elseBlock);
            }

            return new If(expression, block);
        }
    }
}

#include <vector>
#include "factory/IfFactory.h"
#include "factory/ExpressionFactory.h"
#include "factory/BlockFactory.h"
#include "factory/StatementFactory.h"
#include "symbol/Block.h"
#include "symbol/If.h"

namespace dem {
    namespace parser {
        If *IfFactory::produce(std::deque<lexer::Token> &tokens, ParseResults &results) {
            // if_stmt = "if(" conditional ")" ( block | statement )
            //              [ "else" ( block | statement ) ] ;

            // "if("
            expect(tokens, lexer::TokenType::IF, results);
            expect(tokens, lexer::TokenType::OPEN, results);

            // conditional
            Expression *expression = ExpressionFactory::produce(tokens, results);

            // ")"
            expect(tokens, lexer::TokenType::CLOSE, results);

            // block | statement
            Block *block = nullptr;
            if(tokens.front().is(lexer::TokenType::START)) {
                // block
                block = BlockFactory::produce(tokens, results);
            } else {
                // statement
                Statement *statement = StatementFactory::produce(tokens, results);
                std::vector<Statement*> statements{statement};

                block = new Block(expression->token(), statements);
            }

            // [ "else" ( block | statement ) ]
            if(accept(tokens, lexer::TokenType::ELSE)) {
                Block *elseBlock = nullptr;
                if(tokens.front().is(lexer::TokenType::START)) {
                    // block
                    elseBlock = BlockFactory::produce(tokens, results);
                } else {
                    // statement
                    Statement *statement = StatementFactory::produce(tokens, results);
                    std::vector<Statement*> statements{statement};

                    elseBlock = new Block(statement->token(), statements);
                }

                return new If(expression, block, elseBlock);
            }

            return new If(expression, block);
        }
    }
}

#include <symbol/VariableDeclaration.h>
#include <factory/VariableDeclarationFactory.h>
#include "factory/ForFactory.h"
#include "factory/ExpressionFactory.h"
#include "factory/BlockFactory.h"
#include "symbol/For.h"
#include "symbol/Block.h"

namespace dem {
    namespace parser {
        For *ForFactory::produce(std::deque<lexer::Token> &tokens) {
            // for_stmt = "for(" ( terminator | variable_def_stmt | assignment_stmt) ( terminator | conditional ) ( terminator | assignment_stmt ) ")" block ;

            // "for("
            expect(tokens, lexer::TokenType::FOR);
            expect(tokens, lexer::TokenType::OPEN);

            // ( terminator | variable_def_stmt | assignment_stmt )
            Statement *initializerStatement = nullptr;
            if(tokens.front().is(lexer::TokenType::TERMINATOR)) {
                // terminator
                expect(tokens, lexer::TokenType::TERMINATOR);
            } else if(tokens.front().is(lexer::TokenType::VAR)) {
                // variable_def_stmt
                initializerStatement = VariableDeclarationFactory::produce(tokens);
                expect(tokens, lexer::TokenType::TERMINATOR);
            } else {
                // assignment_stmt
                initializerStatement = ExpressionFactory::produce(tokens);
                expect(tokens, lexer::TokenType::TERMINATOR);
            }

            // ( terminator | conditional )
            Expression *conditionalExpression = nullptr;
            if(tokens.front().is(lexer::TokenType::TERMINATOR)) {
                // terminator
                expect(tokens, lexer::TokenType::TERMINATOR);
            } else {
                conditionalExpression = ExpressionFactory::produce(tokens);
                expect(tokens, lexer::TokenType::TERMINATOR);
            }

            // ( terminator | assignment_stmt )
            AssignmentExpression *assignmentExpression = nullptr;
            if(!tokens.front().is(lexer::TokenType::CLOSE))
                assignmentExpression = dynamic_cast<AssignmentExpression*>(ExpressionFactory::produce(tokens));

            // ")"
            expect(tokens, lexer::TokenType::CLOSE);

            // block
            Block *block = BlockFactory::produce(tokens);

            return new For(initializerStatement, conditionalExpression, assignmentExpression, block);
        }
    }
}

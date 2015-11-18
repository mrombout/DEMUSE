#include "factory/ForFactory.h"
#include "factory/AssignmentFactory.h"
#include "factory/ExpressionFactory.h"

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
                // TODO: Variable def
            } else {
                // assignment_stmt
                initializerStatement = AssignmentFactory::produce(tokens);
            }

            // ( terminator | conditional )
            Expression *conditionalExpression = nullptr;
            if(tokens.front().is(lexer::TokenType::TERMINATOR)) {
                // terminator
                expect(tokens, lexer::TokenType::TERMINATOR);
            } else {
                conditionalExpression = ExpressionFactory::produce(tokens);
            }

            // ( terminator | assignment_stmt )
            Assignment *assignmentStatement = AssignmentFactory::produce(tokens);

            return new For(initializerStatement, conditionalExpression, assignmentStatement);
        }
    }
}

#include <symbol/VariableDeclaration.h>
#include <factory/VariableDeclarationFactory.h>
#include "factory/ForFactory.h"
#include "factory/ExpressionFactory.h"
#include "factory/BlockFactory.h"
#include "symbol/For.h"

namespace dem {
    namespace parser {
        For *ForFactory::produce(std::deque<lexer::Token> &tokens, ParseResults &results) {
            // for_stmt = "for(" ( terminator | variable_def_stmt | assignment_stmt) ( terminator | conditional ) ( terminator | assignment_stmt ) ")" block ;

            // "for("
            lexer::Token token = tokens.front();
            expect(tokens, lexer::TokenType::FOR, results);
            expect(tokens, lexer::TokenType::OPEN, results);

            // ( terminator | variable_def_stmt | assignment_stmt )
            Statement *initializerStatement = nullptr;
            if(tokens.front().is(lexer::TokenType::TERMINATOR)) {
                // terminator
                expect(tokens, lexer::TokenType::TERMINATOR, results);
            } else if(tokens.front().is(lexer::TokenType::VAR)) {
                // variable_def_stmt
                initializerStatement = VariableDeclarationFactory::produce(tokens, results);
                expect(tokens, lexer::TokenType::TERMINATOR, results);
            } else {
                // assignment_stmt
                initializerStatement = ExpressionFactory::produce(tokens, results);
                expect(tokens, lexer::TokenType::TERMINATOR, results);
            }

            // ( terminator | conditional )
            Expression *conditionalExpression = nullptr;
            if(tokens.front().is(lexer::TokenType::TERMINATOR)) {
                // terminator
                expect(tokens, lexer::TokenType::TERMINATOR, results);
            } else {
                conditionalExpression = ExpressionFactory::produce(tokens, results);
                expect(tokens, lexer::TokenType::TERMINATOR, results);
            }

            // ( terminator | assignment_stmt )
            AssignmentExpression *assignmentExpression = nullptr;
            if(!tokens.front().is(lexer::TokenType::CLOSE))
                assignmentExpression = dynamic_cast<AssignmentExpression*>(ExpressionFactory::produce(tokens, results));

            // ")"
            expect(tokens, lexer::TokenType::CLOSE, results);

            // block
            Block *block = BlockFactory::produce(tokens, results);

            return new For(token, initializerStatement, conditionalExpression, assignmentExpression, block);
        }
    }
}

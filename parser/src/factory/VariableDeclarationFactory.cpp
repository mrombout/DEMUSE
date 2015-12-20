#include <symbol/expression/AssignmentExpression.h>
#include "factory/ExpressionFactory.h"
#include "factory/VariableDeclarationFactory.h"
#include "symbol/Assignment.h"
#include "symbol/VariableDeclaration.h"

namespace dem {
    namespace parser {
        VariableDeclaration *VariableDeclarationFactory::produce(std::deque<lexer::Token> &tokens, ParseResults &results) {
            // variable_def_stmt = "var" assignment_stmt ;

            // "var"
            expect(tokens, lexer::TokenType::VAR, results);

            // assignment_stmt
            Expression *expression = ExpressionFactory::produce(tokens, results);

            // TODO: Throw proper error when expression is not an assignment expression
            return new VariableDeclaration(static_cast<AssignmentExpression*>(expression));
        }
    }
}

#include "factory/IdentifierFactory.h"
#include "factory/AssignmentFactory.h"
#include "factory/ExpressionFactory.h"
#include "symbol/Identifier.h"
#include "symbol/Assignment.h"

namespace dem {
    namespace parser {
        Assignment *dem::parser::AssignmentFactory::produce(std::deque <lexer::Token> &tokens) {
            // assignment_stmt = lvalue "=" expression ;

            // lvalue
            Identifier *identifier = IdentifierFactory::produce(tokens);

            // "="
            expect(tokens, lexer::TokenType::ASSIGNMENT);

            // expression
            Expression *expression = ExpressionFactory::produce(tokens);

            return new Assignment(identifier, expression);
        }
    }
}

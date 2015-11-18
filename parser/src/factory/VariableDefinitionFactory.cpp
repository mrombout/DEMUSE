#include "factory/VariableDefinitionFactory.h"
#include "factory/AssignmentFactory.h"
#include "symbol/Assignment.h"
#include "symbol/VariableDefinition.h"

namespace dem {
    namespace parser {
        VariableDefinition *VariableDefinitionFactory::produce(std::deque<lexer::Token> &tokens) {
            // variable_def_stmt = "var" assignment_stmt ;

            // "var"
            expect(tokens, lexer::TokenType::VAR);

            // assignment_stmt
            Assignment *assignment = AssignmentFactory::produce(tokens);

            return new VariableDefinition(assignment);
        }
    }
}

#include "factory/ForFactory.h"
#include "factory/AssignmentFactory.h"

namespace dem {
    namespace parser {
        For *ForFactory::produce(std::deque<lexer::Token> &tokens) {
            // for_stmt = "for(" ( terminator | variable_def_stmt | assignment_stmt) ( terminator | conditional ) ( terminator | assignment_stmt ) ")" block ;

            // "for("
            expect(tokens, lexer::TokenType::FOR);
            expect(tokens, lexer::TokenType::OPEN);

            // ( terminator | variable_def_stmt | assignment_stmt )
            Statement *statement = nullptr;
            if(tokens.front().is(lexer::TokenType::TERMINATOR)) {
                // terminator
                expect(tokens, lexer::TokenType::TERMINATOR);
            } else if(tokens.front().is(lexer::TokenType::VAR)) {
                // variable_def_stmt
                // TODO: Variable def
            } else {
                // assignment_stmt
                statement = AssignmentFactory::produce(tokens);
            }

            return nullptr;
        }
    }
}

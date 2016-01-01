#include "symbol/Program.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Program::Program(std::vector<Statement*> statements) :
            Symbol(lexer::Token(lexer::TokenType::UNKNOWN, "", lexer::TokenPosition(0, 0, 0))),
            mStatements(statements) {

        }

        Program::~Program() {

        }

        const std::vector<Statement*> &Program::statements() const {
            return mStatements;
        }

        bool Program::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                for(Statement *statement : mStatements) {
                    statement->accept(visitor);
                }
            }

            return visitor.visitLeave(*this);
        }
    }
}
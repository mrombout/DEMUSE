#include "symbol/Block.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Block::Block(const lexer::Token &token, std::vector<Statement*> statements) :
            Symbol(token),
            mStatements(statements) {

        }

        Block::~Block() {
            for(Statement *statement : mStatements)
                delete statement;
        }

        std::vector<Statement *> &Block::statements() {
            return mStatements;
        }

        bool Block::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                for(Statement *statement : mStatements) {
                    if(!statement->accept(visitor))
                        break;
                }
            }

            return visitor.visitLeave(*this);
        }
    }
}

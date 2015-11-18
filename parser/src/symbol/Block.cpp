#include "symbol/Block.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Block::Block(std::vector<Statement*> statements) :
            mStatements(statements) {

        }

        std::vector<Statement *> &Block::statements() {
            return mStatements;
        }

        bool Block::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                for(Statement *statement : mStatements) {
                    statement->accept(visitor);
                }
            }

            return visitor.visitLeave(*this);
        }
    }
}

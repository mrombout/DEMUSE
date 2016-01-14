#include "symbol/ScopedBlock.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        ScopedBlock::ScopedBlock(Block const &block) :
                Block(block) {

        }

        ScopedBlock::ScopedBlock(const lexer::Token &token, const std::vector<Statement *> &statements) :
                Block(token, statements) {

        }

        bool ScopedBlock::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                for(Statement *statement : statements()) {
                    if(!statement->accept(visitor))
                        break;
                }
            }

            return visitor.visitLeave(*this);
        }
    }
}

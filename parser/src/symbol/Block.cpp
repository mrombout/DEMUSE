#include "symbol/Block.h"

namespace dem {
    namespace parser {
        Block::Block(std::vector<Statement*> statements) :
            mStatements(statements) {

        }

        std::vector<Statement *> &Block::statements() {
            return mStatements;
        }
    }
}

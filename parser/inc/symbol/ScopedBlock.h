#ifndef DEMUSE_SCOPEDBLOCK_H
#define DEMUSE_SCOPEDBLOCK_H

#include "Block.h"

namespace dem {
    namespace parser {
        class ScopedBlock : public Block {
        public:
            ScopedBlock(Block const &block);
            ScopedBlock(const lexer::Token &token, const std::vector<Statement *> &statements);


            virtual bool accept(Visitor &visitor) override;
        };
    }
}

#endif //DEMUSE_SCOPEDBLOCK_H

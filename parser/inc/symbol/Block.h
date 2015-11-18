#ifndef DEMUSE_BLOCK_H
#define DEMUSE_BLOCK_H

#include <vector>
#include "Symbol.h"
#include "Statement.h"

namespace dem {
    namespace parser {
        class Block : public Symbol {
        public:
            Block(std::vector<Statement*> statements);

            std::vector<Statement*> &statements(

            );

        private:
            std::vector<Statement*> mStatements;
        };
    }
}

#endif //DEMUSE_BLOCK_H

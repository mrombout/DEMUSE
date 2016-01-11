#ifndef DEMUSE_BLOCK_H
#define DEMUSE_BLOCK_H

#include <vector>
#include "Symbol.h"
#include "Statement.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents a block (e.g. { ... })
         */
        class Block : public Symbol {
        public:
            Block(const lexer::Token &token, std::vector<Statement*> statements);
            ~Block();

            virtual bool accept(Visitor &visitor);

            std::vector<Statement*> &statements();

        private:
            std::vector<Statement*> mStatements;
        };
    }
}

#endif //DEMUSE_BLOCK_H

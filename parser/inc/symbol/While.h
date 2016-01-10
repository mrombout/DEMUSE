#ifndef DEMUSE_WHILE_H
#define DEMUSE_WHILE_H

#include "CompoundStatement.h"

namespace dem {
    namespace parser {
        class Expression;
        class Block;
    }
}

namespace dem {
    namespace parser {
        /**
         * \brief Represents a while statement (e.g. while(true) { ... })
         */
        class While : public CompoundStatement {
        public:
            While(Expression *expression, Block *block);

            virtual bool accept(Visitor &visitor);

            Expression &expression() const;
            Block &block() const;

        private:
            Expression *mExpression;
            Block *mBlock;
        };
    }
}

#endif //DEMUSE_WHILE_H

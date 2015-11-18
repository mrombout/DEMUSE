#ifndef DEMUSE_WHILE_H
#define DEMUSE_WHILE_H

#include "Statement.h"

namespace dem {
    namespace parser {
        class Expression;
        class Block;
    }
}

namespace dem {
    namespace parser {
        class While : public Statement {
        public:
            While(Expression *expression, Block *block);

        private:
            Expression *mExpression;
            Block *mBlock;
        public:
            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_WHILE_H

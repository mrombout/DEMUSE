#ifndef DEMUSE_WHILE_H
#define DEMUSE_WHILE_H

#include "Statement.h"
#include "expression/Expression.h"
#include "Block.h"

namespace dem {
    namespace parser {
        class While : public Statement {
        public:
            While(Expression *expression, Block *block);

        private:
            Expression *mExpression;
            Block *mBlock;
        };
    }
}

#endif //DEMUSE_WHILE_H

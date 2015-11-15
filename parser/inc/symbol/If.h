#ifndef DEMUSE_IF_H
#define DEMUSE_IF_H

#include "Statement.h"
#include "symbol/Expression.h"
#include "symbol/Block.h"

namespace dem {
    namespace parser {
        class If : public Statement {
        public:
            If(Expression *expression, Block *block);
            If(Expression *expression, Block *block, Block *elseBlock);

        private:
            Expression *mExpression;
            Block *mBlock;
            Block *mElseBlock;
        };
    }
}

#endif //DEMUSE_IF_H

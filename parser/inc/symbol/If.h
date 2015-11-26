#ifndef DEMUSE_IF_H
#define DEMUSE_IF_H

#include "CompoundStatement.h"
#include "symbol/expression/Expression.h"
#include "symbol/Block.h"

namespace dem {
    namespace parser {
        class If : public CompoundStatement {
        public:
            If(Expression *expression, Block *block);
            If(Expression *expression, Block *block, Block *elseBlock);

            virtual bool accept(Visitor &visitor);

            Expression &expression() const;
            Block &block() const;
            Block *elseBlock() const;

        private:
            Expression *mExpression;
            Block *mBlock;
            Block *mElseBlock;
        };
    }
}

#endif //DEMUSE_IF_H

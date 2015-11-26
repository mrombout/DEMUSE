#ifndef DEMUSE_FOR_H
#define DEMUSE_FOR_H

#include "CompoundStatement.h"
#include "symbol/expression/Expression.h"
#include "symbol/expression/AssignmentExpression.h"
#include "symbol/Block.h"

namespace dem {
    namespace parser {
        class For : public CompoundStatement {
        public:
            For(Statement *initialization, Expression *condition, AssignmentExpression *afterThought, Block *block);

            virtual bool accept(Visitor &visitor);

            Statement *initialization() const;
            Expression *condition() const;
            AssignmentExpression *afterThought() const;
            Block &block() const;

        private:
            Statement *mInitialization;
            Expression *mCondition;
            AssignmentExpression *mAfterThought;
            Block *mBlock;
        };
    }
}

#endif //DEMUSE_FOR_H

#ifndef DEMUSE_FOR_H
#define DEMUSE_FOR_H

#include "Statement.h"
#include "symbol/expression/Expression.h"
#include "symbol/expression/AssignmentExpression.h"

namespace dem {
    namespace parser {
        class For : public Statement {
        public:
            For(Statement *initialization, Expression *condition, AssignmentExpression *afterThought);

            virtual bool accept(Visitor &visitor);

            Statement *initialization() const;
            Expression *condition() const;
            AssignmentExpression *afterThought() const;

        private:
            Statement *mInitialization;
            Expression *mCondition;
            AssignmentExpression *mAfterThought;
        };
    }
}

#endif //DEMUSE_FOR_H

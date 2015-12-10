#ifndef DEMUSE_ASSIGNMENTEXPRESSION_H
#define DEMUSE_ASSIGNMENTEXPRESSION_H

#include "BinaryExpression.h"
#include "symbol/Identifier.h"

namespace dem {
    namespace parser {
        class AssignmentExpression : public BinaryExpression<Expression, Expression> {
        public:
            AssignmentExpression(Expression *left, Expression *right);

            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_ASSIGNMENTEXPRESSION_H

#ifndef DEMUSE_ARRAYACCESSEXPRESSION_H
#define DEMUSE_ARRAYACCESSEXPRESSION_H

#include "symbol/expression/Expression.h"
#include "symbol/expression/BinaryExpression.h"

namespace dem {
    namespace parser {
        class ArrayAccessExpression : public BinaryExpression<Expression, Expression> {
        public:
            ArrayAccessExpression(Expression *left, Expression *right);

            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_ARRAYACCESSEXPRESSION_H

#ifndef DEMUSE_EXPONENTEXPRESSION_H
#define DEMUSE_EXPONENTEXPRESSION_H

#include "BinaryExpression.h"

namespace dem {
    namespace parser {
        class ExponentExpression : public BinaryExpression<Expression, Expression> {
        public:
            ExponentExpression(Expression *left, Expression *right);

            virtual bool accept(Visitor &visitor);
        };
    }
}


#endif //DEMUSE_EXPONENTEXPRESSION_H

#ifndef DEMUSE_EXPONENTEXPRESSION_H
#define DEMUSE_EXPONENTEXPRESSION_H

#include "BinaryExpression.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents an exponent expression (e.g. 2^3)
         */
        class ExponentExpression : public BinaryExpression<Expression, Expression> {
        public:
            ExponentExpression(Expression *left, Expression *right);

            virtual bool accept(Visitor &visitor);
        };
    }
}


#endif //DEMUSE_EXPONENTEXPRESSION_H

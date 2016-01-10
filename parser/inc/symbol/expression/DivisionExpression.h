#ifndef DEMUSE_DIVISIONEXPRESSION_H
#define DEMUSE_DIVISIONEXPRESSION_H

#include "BinaryExpression.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents a division (e.g. 10 / 5)
         */
        class DivisionExpression : public BinaryExpression<Expression, Expression> {
        public:
            DivisionExpression(Expression *left, Expression *right);

            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_DIVISIONEXPRESSION_H

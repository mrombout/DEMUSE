#ifndef DEMUSE_MULTIPLICATIONEXPRESSION_H
#define DEMUSE_MULTIPLICATIONEXPRESSION_H

#include "BinaryExpression.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents a multiplication (e.g. 2 * 5)
         */
        class MultiplicationExpression : public BinaryExpression<Expression, Expression> {
        public:
            MultiplicationExpression(Expression *left, Expression *right);

            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_MULTIPLICATIONEXPRESSION_H

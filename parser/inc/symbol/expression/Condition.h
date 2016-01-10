#ifndef DEMUSE_CONDITION_H
#define DEMUSE_CONDITION_H

#include "BinaryExpression.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents a binary condition
         */
        class Condition : public BinaryExpression<Expression, Expression> {
        public:
            Condition(Expression *left, Expression *right);
        };
    }
}

#endif //DEMUSE_CONDITION_H

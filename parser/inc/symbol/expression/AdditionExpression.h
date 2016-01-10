#ifndef DEMUSE_ADDEXPRESSION_H
#define DEMUSE_ADDEXPRESSION_H

#include "BinaryExpression.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents an addition expression (e.g. 1 + 1)
         */
        class AdditionExpression : public BinaryExpression<Expression, Expression> {
        public:
            AdditionExpression(Expression *left, Expression *right);

            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_ADDEXPRESSION_H

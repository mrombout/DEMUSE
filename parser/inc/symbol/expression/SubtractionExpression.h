#ifndef DEMUSE_SUBTRACTIONEXPRESSION_H
#define DEMUSE_SUBTRACTIONEXPRESSION_H

#include "BinaryExpression.h"

namespace dem {
    namespace parser {
        class SubtractionExpression : public BinaryExpression<Expression, Expression> {
        public:
            SubtractionExpression(Expression *left, Expression *right);

            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_SUBTRACTIONEXPRESSION_H

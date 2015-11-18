#ifndef DEMUSE_SUBTRACTIONEXPRESSION_H
#define DEMUSE_SUBTRACTIONEXPRESSION_H

#include "BinaryExpression.h"

namespace dem {
    namespace parser {
        class SubtractionExpression : public BinaryExpression {
        public:
            virtual bool accept(Visitor &visitor);

            SubtractionExpression(Expression *left, Expression *right) :
                    BinaryExpression(left, right) {

            }
        };
    }
}

#endif //DEMUSE_SUBTRACTIONEXPRESSION_H

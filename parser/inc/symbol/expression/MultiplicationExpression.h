#ifndef DEMUSE_MULTIPLICATIONEXPRESSION_H
#define DEMUSE_MULTIPLICATIONEXPRESSION_H

#include "BinaryExpression.h"

namespace dem {
    namespace parser {
        class MultiplicationExpression : public BinaryExpression {
        public:
            MultiplicationExpression(Expression *left, Expression *right);

            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_MULTIPLICATIONEXPRESSION_H

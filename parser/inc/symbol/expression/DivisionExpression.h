#ifndef DEMUSE_DIVISIONEXPRESSION_H
#define DEMUSE_DIVISIONEXPRESSION_H

#include "BinaryExpression.h"

namespace dem {
    namespace parser {
        class DivisionExpression : public BinaryExpression {
        public:
            DivisionExpression(Expression *left, Expression *right);

            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_DIVISIONEXPRESSION_H

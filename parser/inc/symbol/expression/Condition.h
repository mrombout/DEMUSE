#ifndef DEMUSE_CONDITION_H
#define DEMUSE_CONDITION_H

#include "BinaryExpression.h"

namespace dem {
    namespace parser {
        class Condition : public BinaryExpression {
        public:
            Condition(Expression *left, Expression *right);
        };
    }
}

#endif //DEMUSE_CONDITION_H

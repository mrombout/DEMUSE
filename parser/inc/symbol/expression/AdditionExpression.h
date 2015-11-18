#ifndef DEMUSE_ADDEXPRESSION_H
#define DEMUSE_ADDEXPRESSION_H

#include "BinaryExpression.h"

namespace dem {
    namespace parser {
        class Expression;
    }
}

namespace dem {
    namespace parser {
        class AdditionExpression : public BinaryExpression {
        public:
            AdditionExpression(Expression *left, Expression *right);
        };
    }
}

#endif //DEMUSE_ADDEXPRESSION_H

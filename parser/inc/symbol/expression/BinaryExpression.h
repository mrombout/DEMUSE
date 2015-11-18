#ifndef DEMUSE_BINARYEXPRESSION_H
#define DEMUSE_BINARYEXPRESSION_H

#include "Expression.h"

namespace dem {
    namespace parser {
        class BinaryExpression : public Expression {
        public:
            BinaryExpression(Expression *left, Expression *right);

            Expression &left() const;
            Expression &right() const;

        private:
            Expression *mLeft;
            Expression *mRight;
        };
    }
}


#endif //DEMUSE_BINARYEXPRESSION_H

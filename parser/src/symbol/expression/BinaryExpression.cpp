#include "symbol/expression/BinaryExpression.h"

namespace dem {
    namespace parser {
        BinaryExpression::BinaryExpression(Expression *left, Expression *right) :
                mLeft(left),
                mRight(right) {

        }

        Expression &BinaryExpression::left() const {
            return *mLeft;
        }

        Expression &BinaryExpression::right() const {
            return *mRight;
        }
    }
}

#include "symbol/expression/MultiplicationExpression.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        MultiplicationExpression::MultiplicationExpression(Expression *left, Expression *right) :
                BinaryExpression(left, right) {

        }

        bool MultiplicationExpression::accept(Visitor &visitor) {
            if (visitor.visitEnter(*this)) {
                left().accept(visitor);
                right().accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}

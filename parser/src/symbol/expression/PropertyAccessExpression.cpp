#include "symbol/expression/PropertyAccessExpression.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        PropertyAccessExpression::PropertyAccessExpression(Expression *left, Expression *right)
                : BinaryExpression(left, right) { }

        bool PropertyAccessExpression::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                left().accept(visitor);
                right().accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}

#include "symbol/expression/ArrayAccessExpression.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        ArrayAccessExpression::ArrayAccessExpression(Expression *left, Expression *right) :
            BinaryExpression(left, right) {

        }

        bool dem::parser::ArrayAccessExpression::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                left().accept(visitor);
                right().accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}

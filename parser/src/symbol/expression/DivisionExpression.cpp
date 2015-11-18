#include "symbol/expression/DivisionExpression.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        DivisionExpression::DivisionExpression(Expression *left, Expression *right) :
                BinaryExpression(left, right) {

        }

        bool DivisionExpression::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                left().accept(visitor);
                right().accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}
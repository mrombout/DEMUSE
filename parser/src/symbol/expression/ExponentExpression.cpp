#include "symbol/expression/ExponentExpression.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        ExponentExpression::ExponentExpression(Expression *left, Expression *right) :
                BinaryExpression(left, right) {

        }

        bool ExponentExpression::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                left().accept(visitor);
                right().accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}
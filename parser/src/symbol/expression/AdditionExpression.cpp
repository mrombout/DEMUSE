#include "symbol/expression/AdditionExpression.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        AdditionExpression::AdditionExpression(Expression *left, Expression *right) :
            BinaryExpression(left, right) {

        }

        bool AdditionExpression::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                left().accept(visitor);
                right().accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}

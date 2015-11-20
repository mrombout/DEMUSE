#include "symbol/expression/AssignmentExpression.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        AssignmentExpression::AssignmentExpression(Identifier *left, Expression *right) :
            BinaryExpression(left, right) {

        }

        bool dem::parser::AssignmentExpression::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                left().accept(visitor);
                right().accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}

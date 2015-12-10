#include "symbol/expression/AssignmentExpression.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        AssignmentExpression::AssignmentExpression(Expression *left, Expression *right) :
            BinaryExpression(left, right) {
            // TODO: Make proper lvalue base class for identifier and arrayaccess?
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

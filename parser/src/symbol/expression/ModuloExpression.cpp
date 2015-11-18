#include "symbol/expression/ModuloExpression.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        ModuloExpression::ModuloExpression(Expression *left, Expression *right) :
                BinaryExpression(left, right) {

        }

        bool ModuloExpression::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                left().accept(visitor);
                right().accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}

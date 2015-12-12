#include "symbol/expression/SubtractionExpression.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        SubtractionExpression::SubtractionExpression(Expression *left, Expression *right) :
            BinaryExpression(left, right) {

        }

        bool dem::parser::SubtractionExpression::accept(dem::parser::Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                left().accept(visitor);
                right().accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}

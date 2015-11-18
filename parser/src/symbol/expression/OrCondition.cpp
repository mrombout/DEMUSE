#include "symbol/expression/OrCondition.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        OrCondition::OrCondition(Expression *left, Expression *right) :
            Condition(left, right) {

        }

        bool OrCondition::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                left().accept(visitor);
                right().accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}
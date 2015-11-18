#include "symbol/expression/StrictEqualCondition.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        StrictEqualCondition::StrictEqualCondition(Expression *left, Expression *right) :
            Condition(left, right) {

        }

        bool StrictEqualCondition::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                left().accept(visitor);
                right().accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}
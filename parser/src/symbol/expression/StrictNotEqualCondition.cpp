#include "symbol/expression/StrictNotEqualCondition.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        StrictNotEqualCondition::StrictNotEqualCondition(Expression *left, Expression *right) :
            Condition(left, right) {

        }

        bool StrictNotEqualCondition::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                left().accept(visitor);
                right().accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}
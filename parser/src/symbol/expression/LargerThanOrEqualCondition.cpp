#include "symbol/expression/LargerThanOrEqualCondition.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        LargerThanOrEqualCondition::LargerThanOrEqualCondition(Expression *left, Expression *right) :
                Condition(left, right) {

        }

        bool LargerThanOrEqualCondition::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                left().accept(visitor);
                right().accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}
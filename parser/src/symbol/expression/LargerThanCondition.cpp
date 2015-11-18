#include "symbol/expression/LargerThanCondition.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        LargerThanCondition::LargerThanCondition(Expression *left, Expression *right) :
            Condition(left, right) {

        }

        bool LargerThanCondition::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                left().accept(visitor);
                right().accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}

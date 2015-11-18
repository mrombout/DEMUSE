#include "symbol/expression/SmallerThanCondition.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        SmallerThanCondition::SmallerThanCondition(Expression *left, Expression *right) :
                Condition(left, right) {

        }

        bool SmallerThanCondition::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                left().accept(visitor);
                right().accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}
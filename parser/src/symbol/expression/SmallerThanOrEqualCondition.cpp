#include "symbol/expression/SmallerThanOrEqualCondition.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        SmallerThanOrEqualCondition::SmallerThanOrEqualCondition(Expression *left, Expression *right) :
            Condition(left, right) {

        }

        bool SmallerThanOrEqualCondition::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                left().accept(visitor);
                right().accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}
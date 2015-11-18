#include "symbol/expression/EqualCondition.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        EqualCondition::EqualCondition(Expression *left, Expression *right) :
                Condition(left, right) {

        }

        bool EqualCondition::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                left().accept(visitor);
                right().accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}
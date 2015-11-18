#include "symbol/expression/NotEqualCondition.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        NotEqualCondition::NotEqualCondition(Expression *left, Expression *right) :
                Condition(left, right) {

        }

        bool NotEqualCondition::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                left().accept(visitor);
                right().accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}

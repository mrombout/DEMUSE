#include "symbol/expression/AndCondition.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        AndCondition::AndCondition(Expression *left, Expression *right) :
                Condition(left, right) {

        }

        bool AndCondition::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                left().accept(visitor);
                right().accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}

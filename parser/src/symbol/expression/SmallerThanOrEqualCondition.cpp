#include "symbol/expression/SmallerThanOrEqualCondition.h"

namespace dem {
    namespace parser {
        SmallerThanOrEqualCondition::SmallerThanOrEqualCondition(Expression *left, Expression *right) :
            Condition(left, right) {

        }
    }
}
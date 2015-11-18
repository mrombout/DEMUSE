#include "symbol/expression/LargerThanOrEqualCondition.h"

namespace dem {
    namespace parser {
        LargerThanOrEqualCondition::LargerThanOrEqualCondition(Expression *left, Expression *right) :
                Condition(left, right) {

        }
    }
}
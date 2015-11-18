#include "symbol/expression/StrictEqualCondition.h"

namespace dem {
    namespace parser {
        StrictEqualCondition::StrictEqualCondition(Expression *left, Expression *right) :
            Condition(left, right) {

        }
    }
}
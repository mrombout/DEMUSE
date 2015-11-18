#include "symbol/expression/StrictNotEqualCondition.h"

namespace dem {
    namespace parser {
        StrictNotEqualCondition::StrictNotEqualCondition(Expression *left, Expression *right) :
            Condition(left, right) {

        }
    }
}
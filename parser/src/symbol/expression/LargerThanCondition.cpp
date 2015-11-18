#include "symbol/expression/LargerThanCondition.h"

namespace dem {
    namespace parser {
        LargerThanCondition::LargerThanCondition(Expression *left, Expression *right) :
            Condition(left, right) {

        }
    }
}

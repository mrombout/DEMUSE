#include "symbol/expression/OrCondition.h"

namespace dem {
    namespace parser {
        OrCondition::OrCondition(Expression *left, Expression *right) :
            Condition(left, right) {

        }
    }
}
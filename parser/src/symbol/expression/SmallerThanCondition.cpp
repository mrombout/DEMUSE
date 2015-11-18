#include "symbol/expression/SmallerThanCondition.h"

namespace dem {
    namespace parser {
        SmallerThanCondition::SmallerThanCondition(Expression *left, Expression *right) :
                Condition(left, right) {

        }
    }
}
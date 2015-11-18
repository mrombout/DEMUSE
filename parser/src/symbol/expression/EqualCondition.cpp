#include "symbol/expression/EqualCondition.h"

namespace dem {
    namespace parser {
        EqualCondition::EqualCondition(Expression *left, Expression *right) :
                Condition(left, right) {

        }
    }
}
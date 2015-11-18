#include "symbol/expression/AndCondition.h"

namespace dem {
    namespace parser {
        AndCondition::AndCondition(Expression *left, Expression *right) :
                Condition(left, right) {

        }
    }
}

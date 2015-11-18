#include "symbol/expression/Condition.h"

namespace dem {
    namespace parser {
        Condition::Condition(Expression *left, Expression *right) :
            BinaryExpression(left, right) {

        }
    }
}

#include "symbol/expression/NotEqualCondition.h"

namespace dem {
    namespace parser {
        NotEqualCondition::NotEqualCondition(Expression *left, Expression *right) :
                Condition(left, right) {

        }
    }
}

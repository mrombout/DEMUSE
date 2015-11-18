#include "symbol/expression/AddExpression.h"

namespace dem {
    namespace parser {
        AddExpression::AddExpression(Expression *left, Expression *right) :
            BinaryExpression(left, right) {

        }
    }
}

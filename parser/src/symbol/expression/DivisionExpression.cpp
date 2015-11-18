#include "symbol/expression/DivisionExpression.h"

namespace dem {
    namespace parser {
        DivisionExpression::DivisionExpression(Expression *left, Expression *right) :
                BinaryExpression(left, right) {

        }
    }
}
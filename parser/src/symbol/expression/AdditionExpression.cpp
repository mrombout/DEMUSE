#include "symbol/expression/AdditionExpression.h"

namespace dem {
    namespace parser {
        AdditionExpression::AdditionExpression(Expression *left, Expression *right) :
            BinaryExpression(left, right) {

        }
    }
}

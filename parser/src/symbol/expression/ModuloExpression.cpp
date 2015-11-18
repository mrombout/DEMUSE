#include "symbol/expression/ModuloExpression.h"

namespace dem {
    namespace parser {
        ModuloExpression::ModuloExpression(Expression *left, Expression *right) :
                BinaryExpression(left, right) {

        }
    }
}

#include "symbol/Assignment.h"

namespace dem {
    namespace parser {
        Assignment::Assignment(Identifier *identifier, Expression *expression) :
            mIdentifier(identifier),
            mExpression(expression) {

        }
    }
}
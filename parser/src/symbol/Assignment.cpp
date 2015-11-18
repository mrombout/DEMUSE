#include "symbol/Assignment.h"

namespace dem {
    namespace parser {
        Assignment::Assignment(Identifier *identifier, Expression *expression) :
            mIdentifier(identifier),
            mExpression(expression) {

        }

        Identifier &Assignment::identifier() const {
            return *mIdentifier;
        }

        Expression &Assignment::expression() const {
            return *mExpression;
        }
    }
}
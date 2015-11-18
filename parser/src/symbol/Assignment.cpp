#include "symbol/Assignment.h"
#include "Visitor.h"

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

        bool Assignment::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                identifier().accept(visitor);
                expression().accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}
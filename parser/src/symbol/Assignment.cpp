#include <stdexcept>
#include "symbol/Assignment.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Assignment::Assignment(Identifier *identifier, Expression *expression) :
            Statement(identifier->token()),
            mIdentifier(identifier),
            mExpression(expression) {
            if(!mIdentifier)
                throw std::invalid_argument("Argument 'identifier' may not be null.");
            if(!mExpression)
                throw std::invalid_argument("Argument 'expression' may not be null.");
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
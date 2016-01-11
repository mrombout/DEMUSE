#include <stdexcept>
#include "symbol/Return.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Return::Return(Expression *expression) :
            Statement(expression->token()),
            mExpression(expression) {
            if(!mExpression)
                throw std::invalid_argument("Argument 'expression' may not be null.");
        }

        Return::~Return() {
            delete mExpression;
        }

        bool Return::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                mExpression->accept(visitor);
            }

            return visitor.visitLeave(*this);
        }

        Expression &Return::expression() const {
            return *mExpression;
        }
    }
}

#include "symbol/Return.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Return::Return(Expression *expression) :
            Statement(expression->token()),
            mExpression(expression) {

        }

        bool Return::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                mExpression->accept(visitor);
            }

            return visitor.visitLeave(*this);
        }

        Expression *Return::expression() const {
            return mExpression;
        }
    }
}

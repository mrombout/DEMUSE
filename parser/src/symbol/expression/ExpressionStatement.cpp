#include <stdexcept>
#include "symbol/expression/ExpressionStatement.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        ExpressionStatement::ExpressionStatement(Expression *expression) :
            Statement(expression->token()),
            mExpression(expression) {
            if(!mExpression)
                throw std::invalid_argument("Argument 'expression' may not be null.");
        }

        Expression &ExpressionStatement::expression() const {
            return *mExpression;
        }

        bool ExpressionStatement::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                mExpression->accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}

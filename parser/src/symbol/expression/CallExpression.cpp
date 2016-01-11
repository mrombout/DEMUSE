#include "symbol/expression/CallExpression.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        CallExpression::CallExpression(Expression *callee, std::vector<Expression *> arguments) :
            Expression(callee->token()),
            mCallee(callee),
            mArguments(arguments) {
            if(!mCallee)
                throw std::invalid_argument("Argument 'mCallee' may not be null.");
        }

        Expression &CallExpression::callee() const {
            return *mCallee;
        }

        const std::vector<Expression*> &CallExpression::arguments() const {
            return mArguments;
        }

        bool CallExpression::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                mCallee->accept(visitor);
                for(Expression *expression : mArguments) {
                    expression->accept(visitor);
                }
            }

            return visitor.visitLeave(*this);
        }
    }
}

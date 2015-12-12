#include "symbol/expression/CallExpression.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        CallExpression::CallExpression(Expression *callee, std::vector<Expression *> arguments) :
            mCallee(callee),
            mArguments(arguments) {

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

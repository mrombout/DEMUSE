#include "symbol/expression/FunctionCallExpression.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        FunctionCallExpression::FunctionCallExpression(ArgumentList *argumentList, Expression *expression) :
            mExpression(expression),
            mArgumentList(argumentList) {

        }

        Expression *FunctionCallExpression::expression() const {
            return mExpression;
        }

        ArgumentList *FunctionCallExpression::argumentList() const {
            return mArgumentList;
        }

        bool FunctionCallExpression::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                mArgumentList->accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}

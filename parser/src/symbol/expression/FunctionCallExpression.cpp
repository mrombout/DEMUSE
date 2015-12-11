#include <iostream>
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
            std::cout << "[ACCEPT] FunctionCallExpression" << std::endl;
            if(visitor.visitEnter(*this)) {
                mExpression->accept(visitor);
                mArgumentList->accept(visitor);
            }

            return visitor.visitLeave(*this);
        }

        const std::string &FunctionCallExpression::name() const {
            if(Identifier *identifier = dynamic_cast<Identifier*>(mExpression))
                return identifier->name();
            throw "Can't identify from expression."; // TODO: Throw proper exception
        }
    }
}

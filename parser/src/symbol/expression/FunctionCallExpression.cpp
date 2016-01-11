#include <iostream>
#include "exception/ParsingException.h"
#include "symbol/expression/FunctionCallExpression.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        FunctionCallExpression::FunctionCallExpression(ArgumentList *argumentList, Expression *expression) :
            Expression(expression->token()),
            mExpression(expression),
            mArgumentList(argumentList) {
            if(!mExpression)
                throw std::invalid_argument("Argument 'argumentList' may not be null.");
            if(!mArgumentList)
                throw std::invalid_argument("Argument 'expression' may not be null.");
        }

        Expression &FunctionCallExpression::expression() const {
            return *mExpression;
        }

        ArgumentList &FunctionCallExpression::argumentList() const {
            return *mArgumentList;
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
            throw ParsingException(mExpression->token(), "Can't identify from expression.");
        }
    }
}

#include "symbol/expression/UnaryExpression.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        UnaryExpression::UnaryExpression(std::string op, Expression *argument) :
            Expression(argument->token()),
            mOperator(op),
            mArgument(argument) {

        }

        const std::string &UnaryExpression::op() const {
            return mOperator;
        }

        Expression &UnaryExpression::argument() const {
            return *mArgument;
        }

        bool UnaryExpression::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                mArgument->accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}

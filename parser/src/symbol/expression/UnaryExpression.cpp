#include "symbol/expression/UnaryExpression.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        UnaryExpression::UnaryExpression(lexer::Token op, Expression *argument) :
            Expression(op),
            mOperator(op),
            mArgument(argument) {

        }

        const std::string &UnaryExpression::op() const {
            return mOperator.content();
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

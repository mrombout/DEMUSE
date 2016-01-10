#include "symbol/expression/ArrayAccessExpression.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        ArrayAccessExpression::ArrayAccessExpression(Expression *array, Expression *index, bool computed) :
            Expression(array->token()),
            mObject(array),
            mIndex(index),
            mComputed(computed) {

        }

        Expression &ArrayAccessExpression::object() {
            return *mObject;
        }

        Expression &ArrayAccessExpression::index() {
            return *mIndex;
        }

        bool ArrayAccessExpression::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                mObject->accept(visitor);
                mIndex->accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}

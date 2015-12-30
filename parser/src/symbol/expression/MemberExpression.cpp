#include "symbol/expression/MemberExpression.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        MemberExpression::MemberExpression(Expression *object, Expression *property, bool computed) :
            Expression(object->token()),
            mObject(object),
            mProperty(property),
            mComputed(computed) {

        }

        bool MemberExpression::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                mObject->accept(visitor);
                mProperty->accept(visitor);
            }

            return visitor.visitLeave(*this);
        }

        Expression &MemberExpression::object() const {
            return *mObject;
        }

        Expression &MemberExpression::property() const {
            return *mProperty;
        }
    }
}

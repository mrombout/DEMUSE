#include "symbol/expression/MemberExpression.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        MemberExpression::MemberExpression(Expression *object, Expression *property, bool computed) :
            Expression(object->token()),
            mObject(object),
            mProperty(property),
            mComputed(computed) {
            if(!mObject)
                throw std::invalid_argument("Argument 'object' may not be null.");
            if(!mProperty)
                throw std::invalid_argument("Argument 'property' may not be null.");
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

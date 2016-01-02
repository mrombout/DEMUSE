#include <value/function/UserFunction.h>
#include "value/Property.h"

namespace dem {
    namespace compiler {
        Property::Property(ObjectValue *parent, parser::Identifier *identifier, Value *value) :
                Variable(identifier, value),
                mParent(parent) {

        }

        void Property::setValue(Value *value) {
            if(dynamic_cast<UserFunction*>(value)) {
                UserFunction *userFunction = dynamic_cast<UserFunction*>(value);
                userFunction->setParent(mParent);
            }
            Variable::setValue(value);
        }
    }
}
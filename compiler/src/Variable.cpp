#include "Variable.h"

namespace dem {
    namespace compiler {
        Variable::Variable(parser::Identifier *identifier, Value *value) :
            mIdentifier(identifier),
            mValue(value) {

        }

        parser::Identifier *Variable::identifier() const {
            return mIdentifier;
        }

        Value *Variable::value() const {
            return mValue;
        }
    }
}

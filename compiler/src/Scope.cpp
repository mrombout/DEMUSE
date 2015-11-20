#include "Scope.h"
#include "value/NullValue.h"

namespace dem {
    namespace compiler {
        Scope::Scope(Scope *parent) :
            mParent(parent) {

        }

        void Scope::declareVariable(parser::Identifier *identifier) {
            mVariables[identifier] = new Variable(identifier, new NullValue());
        }
    }
}

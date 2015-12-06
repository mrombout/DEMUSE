#include <vector>
#include "value/function/InternalFunction.h"

namespace dem {
    namespace compiler {
        void InternalFunction::mapScope(Scope &scope, std::vector<Value*> &arguments) {
            int curIndex = 0;
            for(Value *value : arguments) {
                scope.declareVariable(new parser::Identifier(std::to_string(++curIndex)), value);
            }
        }
    }
}

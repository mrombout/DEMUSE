#ifndef DEMUSE_INTERNALFUNCTION_H
#define DEMUSE_INTERNALFUNCTION_H

#include "value/function/FunctionValue.h"
#include "Scope.h"
#include "value/Value.h"

namespace dem {
    namespace compiler {
        class InternalFunction : public FunctionValue {
        public:
            virtual void mapScope(Scope &scope, std::vector<Value*> &arguments);
        };
    }
}

#endif //DEMUSE_INTERNALFUNCTION_H

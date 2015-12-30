#ifndef DEMUSE_FUNCTIONVALUE_H
#define DEMUSE_FUNCTIONVALUE_H

#include "value/ObjectValue.h"
#include "symbol/ParameterList.h"
#include "symbol/Block.h"
#include "Compiler.h"

namespace dem {
    namespace compiler {
        class FunctionValue : public ObjectValue {
        public:
            virtual void mapScope(Scope &scope, std::vector<Value*> &arguments) = 0;
        };
    }
}

#endif //DEMUSE_FUNCTIONVALUE_H

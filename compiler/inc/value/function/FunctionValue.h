#ifndef DEMUSE_FUNCTIONVALUE_H
#define DEMUSE_FUNCTIONVALUE_H

#include "value/ObjectValue.h"
#include "symbol/ParameterList.h"
#include "symbol/Block.h"
#include "Compiler.h"

namespace dem {
    namespace compiler {
        /**
         * \brief Represents a function
         *
         * NOTE: Since all objects are now callable, isn't this Value obsolete?
         */
        class FunctionValue : public ObjectValue {
        public:
            FunctionValue();
            FunctionValue(ObjectValue *parent);

            virtual void mapScope(ObjectValue &functionScope, std::vector<Value*> &arguments) = 0;
        };
    }
}

#endif //DEMUSE_FUNCTIONVALUE_H

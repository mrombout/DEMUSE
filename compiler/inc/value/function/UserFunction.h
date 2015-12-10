#ifndef DEMUSE_USERFUNCTION_H
#define DEMUSE_USERFUNCTION_H

#include "Compiler.h"
#include "FunctionValue.h"

namespace dem {
    namespace compiler {
        class UserFunction : public FunctionValue {
        public:
            UserFunction(Compiler &compiler, parser::ParameterList &parameterList, parser::Block &block);

            void mapScope(Scope &scope, std::vector<Value*> &arguments) override;
            virtual Value *operator()(Scope &scope);

        private:
            Compiler &mCompiler;
            parser::ParameterList &mParameterList;
            parser::Block &mBlock;
        };
    }
}

#endif //DEMUSE_USERFUNCTION_H

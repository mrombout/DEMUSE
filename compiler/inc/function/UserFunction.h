#ifndef DEMUSE_USERFUNCTION_H
#define DEMUSE_USERFUNCTION_H

#include "symbol/FunctionDefinition.h"
#include "Function.h"
#include "Compiler.h"

namespace dem {
    namespace compiler {
        class UserFunction : public Function {
        public:
            UserFunction(Compiler &compiler, parser::FunctionDefinition &functionDefinition);

            virtual parser::Identifier &identifier() const;

            virtual void mapScope(Scope &scope, std::vector<Value *> &arguments) const override;
            virtual Value *execute(Scope &scope) const;

        private:
            Compiler &mCompiler;
            parser::FunctionDefinition &mFunctionDefinition;
        };
    }
}

#endif //DEMUSE_USERFUNCTION_H

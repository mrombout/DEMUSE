/*
#include "exception/RuntimeException.h"
#include "function/UserFunction.h"
#include "value/NullValue.h"
#include "Scope.h"

namespace dem {
    namespace compiler {
        UserFunction::UserFunction(Compiler &compiler, parser::FunctionDefinition &functionDefinition) :
            mCompiler(compiler),
            mFunctionDefinition(functionDefinition) {

        }

        parser::Identifier &UserFunction::identifier() const {
            // TODO: Identifier may be null
            return *mFunctionDefinition.identifier();
        }

        void UserFunction::mapScope() const {

        }

        Value *UserFunction::execute(Scope &scope) const {
            mFunctionDefinition.block().accept(mCompiler);

            return mCompiler.returnValue();
        }
    }
}
*/
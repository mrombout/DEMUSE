#include "function/UserFunction.h"

namespace dem {
    namespace compiler {
        UserFunction::UserFunction(Compiler &compiler, parser::FunctionDefinition &functionDefinition) :
            mCompiler(compiler),
            mFunctionDefinition(functionDefinition) {

        }

        parser::Identifier &UserFunction::identifier() const {
            return mFunctionDefinition.identifier();
        }

        Value *UserFunction::execute(Scope &scope) const {
            mFunctionDefinition.block().accept(mCompiler);
        }
    }
}
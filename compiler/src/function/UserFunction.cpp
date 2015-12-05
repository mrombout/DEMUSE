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
            return mFunctionDefinition.identifier();
        }

        void UserFunction::mapScope(Scope &scope, std::vector<Value*> &arguments) const {
            if(mFunctionDefinition.parameterList().numParameters() == 0)
                return;

            parser::ParameterList &parameterList = mFunctionDefinition.parameterList();
            int numParameters = parameterList.numParameters();
            if(numParameters != arguments.size()) {
                // TODO: We could be more forgiving like JS. Default value for missing arguments, ignore extras
                throw RuntimeException(parameterList, "Wrong number of arguments. Expected '" + std::to_string(numParameters) + "', but got '" + std::to_string(arguments.size()) + "'");
            }

            unsigned int i = 0;
            for(parser::Identifier *identifier : mFunctionDefinition.parameterList().parameters()) {
                scope.declareVariable(identifier, arguments.at(i++));
            }
        }

        Value *UserFunction::execute(Scope &scope) const {
            mFunctionDefinition.block().accept(mCompiler);

            return mCompiler.returnValue();
        }
    }
}

#include "value/function/UserFunction.h"
#include "exception/RuntimeException.h"

namespace dem {
    namespace compiler {
        UserFunction::UserFunction(Compiler &compiler, parser::ParameterList &parameterList, parser::Block &block) :
                mCompiler(compiler),
                mParameterList(parameterList),
                mBlock(block) {

        }

        Value *UserFunction::operator()(Scope &scope) {
            mBlock.accept(mCompiler);

            return mCompiler.returnValue();
        }

        void UserFunction::mapScope(Scope &scope, std::vector<Value*> &arguments) {
            if(mParameterList.numParameters() == 0)
                return;

            int numParameters = mParameterList.numParameters();
            if(numParameters != arguments.size()) {
                // TODO: We could be more forgiving like JS. Default value for missing arguments, ignore extras
                throw RuntimeException(mParameterList, "Wrong number of arguments. Expected '" + std::to_string(numParameters) + "', but got '" + std::to_string(arguments.size()) + "'");
            }

            unsigned int i = 0;
            for(parser::Identifier *identifier : mParameterList.parameters()) {
                scope.declareVariable(identifier, arguments.at(i++));
            }
        }
    }
}

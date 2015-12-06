#include "exception/RuntimeException.h"
#include "value/Value.h"
#include "value/FunctionValue.h"

namespace dem {
    namespace compiler {
        FunctionValue::FunctionValue(Compiler &compiler, parser::ParameterList &parameterList, parser::Block &block) :
            mCompiler(compiler),
            mParameterList(parameterList),
            mBlock(block) {

        }

        Value *FunctionValue::add(Value *b) {
            return nullptr;
        }

        Value *FunctionValue::subtract(Value *b) {
            return nullptr;
        }

        Value *FunctionValue::multiply(Value *b) {
            return nullptr;
        }

        Value *FunctionValue::divide(Value *b) {
            return nullptr;
        }

        Value *FunctionValue::modulo(Value *b) {
            return nullptr;
        }

        Value *FunctionValue::exponent(Value *b) {
            return nullptr;
        }

        double FunctionValue::asNumber() const {
            return 0;
        }

        bool FunctionValue::asBool() const {
            return false;
        }

        std::string FunctionValue::asString() const {
            return "function(){ ... }";
        }

        bool FunctionValue::operator==(const Value &other) {
            return false;
        }

        bool FunctionValue::operator!=(const Value &other) {
            return false;
        }

        bool FunctionValue::operator<(const Value &other) {
            return false;
        }

        bool FunctionValue::operator<=(const Value &other) {
            return false;
        }

        bool FunctionValue::operator>(const Value &other) {
            return false;
        }

        bool FunctionValue::operator>=(const Value &other) {
            return false;
        }

        Value *FunctionValue::operator[](const int index) {
            return nullptr;
        }

        Value *FunctionValue::operator[](const std::string &index) {
            return nullptr;
        }

        Value *FunctionValue::operator()(Scope &scope) {
            mBlock.accept(mCompiler);

            return mCompiler.returnValue();
        }

        void FunctionValue::mapScope(Scope &scope, std::vector<Value*> &arguments) {
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

#include "value/function/UserFunction.h"
#include "exception/RuntimeException.h"

namespace dem {
    namespace compiler {
        UserFunction::UserFunction(Compiler &compiler, parser::ParameterList &parameterList, parser::Block &block) :
            UserFunction(compiler, nullptr, parameterList, block) {

        }

        UserFunction::UserFunction(Compiler &compiler, ObjectValue *parent, parser::ParameterList &parameterList, parser::Block &block) :
                FunctionValue(parent),
                mCompiler(compiler),
                mParameterList(parameterList),
                mBlock(block) {

        }

        Value *UserFunction::operator()() {
            mBlock.accept(mCompiler);

            return mCompiler.returnValue();
        }

        void UserFunction::mapScope(std::vector<Value*> &arguments) {
            if(mParameterList.numParameters() == 0)
                return;

            int numParameters = mParameterList.numParameters();
            if(numParameters != arguments.size()) {
                throw RuntimeException("Wrong number of arguments. Expected '" + std::to_string(numParameters) + "', but got '" + std::to_string(arguments.size()) + "'");
            }

            unsigned int i = 0;
            for(parser::Identifier *identifier : mParameterList.parameters()) {
                declareVariable(identifier, arguments.at(i++));
            }
        }

        Value *UserFunction::add(Value *b) {
            throw RuntimeException("Functions do not support addition operations.");
        }

        Value *UserFunction::subtract(Value *b) {
            throw RuntimeException("Functions do not support subtraction operations.");
        }

        Value *UserFunction::multiply(Value *b) {
            throw RuntimeException("Functions do not support multiplication operations.");
        }

        Value *UserFunction::divide(Value *b) {
            throw RuntimeException("Functions do not support division operations.");
        }

        Value *UserFunction::modulo(Value *b) {
            throw RuntimeException("Functions do not support division modulo operations.");
        }

        Value *UserFunction::exponent(Value *b) {
            throw RuntimeException("Functions do not support division exponent operations.");
        }

        double UserFunction::asNumber() const {
            throw RuntimeException("Value of type 'Function' can not implicitly be converted to value of type 'Number'.");
        }

        bool UserFunction::asBool() const {
            throw RuntimeException("Value of type 'Function' can not implicitly be converted to value of type 'Bool'.");
        }

        parser::Note UserFunction::asNote() const {
            throw RuntimeException("Value of type 'Function' can not implicitly be converted to value of type 'Note'.");
        }

        std::string UserFunction::asString() const {
            return "Function";
        }

        bool UserFunction::operator==(const Value &other) {
            throw RuntimeException("Functions do not support '==' operations.");
        }

        bool UserFunction::operator!=(const Value &other) {
            throw RuntimeException("Functions do not support '!=' operations.");
        }

        bool UserFunction::operator<(const Value &other) {
            throw RuntimeException("Functions do not support '<' operations.");
        }

        bool UserFunction::operator<=(const Value &other) {
            throw RuntimeException("Functions do not support '<=' operations.");
        }

        bool UserFunction::operator>(const Value &other) {
            throw RuntimeException("Functions do not support '>' operations.");
        }

        bool UserFunction::operator>=(const Value &other) {
            throw RuntimeException("Functions do not support '>=' operations.");
        }

        Value *UserFunction::operator[](const int index) {
            throw RuntimeException("Functions do not support '[]' operations.");
        }

        Variable *UserFunction::operator[](const std::string &index) {
            throw RuntimeException("Functions do not support '.' operations.");
        }
    }
}

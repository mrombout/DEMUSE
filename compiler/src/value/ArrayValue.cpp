#include <sstream>
#include "exception/RuntimeException.h"
#include "value/function/InternalLambdaFunction.h"
#include "value/NullValue.h"
#include "value/NumberValue.h"
#include "value/ArrayValue.h"

namespace dem {
    namespace compiler {
        ArrayValue::ArrayValue(std::vector<Variable*> values) :
            mValues(values) {
            mProperties["length"] = new Variable(new parser::Identifier("length"), new NumberValue(mValues.size()));
            mProperties["push"] = new Variable(new parser::Identifier("charAt"), new InternalLambdaFunction(this, [this](InternalLambdaFunction &function) -> Value* {
                mValues.push_back(function.variable(new parser::Identifier("1")));

                return new NullValue();
            }));
            mProperties["pop"] = new Variable(new parser::Identifier("pop"), new InternalLambdaFunction(this, [this](InternalLambdaFunction &function) -> Value* {
                Variable *variable = mValues.back();
                mValues.pop_back();

                return variable->realValue();
            }));
        }

        Value *dem::compiler::ArrayValue::add(Value *b) {
            throw RuntimeException("Arrays do not support addition operations.");
        }

        Value *dem::compiler::ArrayValue::subtract(Value *b) {
            throw RuntimeException("Arrays do not support subtraction operations.");
        }

        Value *dem::compiler::ArrayValue::multiply(Value *b) {
            throw RuntimeException("Arrays do not support multiplication operations.");
        }

        Value *dem::compiler::ArrayValue::divide(Value *b) {
            throw RuntimeException("Arrays do not support division operations.");
        }

        Value *dem::compiler::ArrayValue::modulo(Value *b) {
            throw RuntimeException("Arrays do not support modulo operations.");
        }

        Value *dem::compiler::ArrayValue::exponent(Value *b) {
            throw RuntimeException("Arrays do not support exponent operations.");
        }

        Value *ArrayValue::value() {
            return this;
        }

        double ArrayValue::asNumber() const {
            throw RuntimeException("Value of type 'Array' can not implicitly be converted to value of type 'Number'.");
        }

        bool ArrayValue::asBool() const {
            throw RuntimeException("Value of type 'Array' can not implicitly be converted to value of type 'Bool'.");
        }

        std::string ArrayValue::asString() const {
            std::stringstream ss;
            ss << "[";

            const char *separator = "";
            for(Value *value : mValues) {
                ss << separator << value->asString();
                separator = ", ";
            }

            ss << "]";

            return ss.str();
        }

        parser::Note ArrayValue::asNote() const {
            throw RuntimeException("Value of type 'Array' can not implicitly be converted to value of type 'Note'.");
        }

        bool ArrayValue::operator==(const Value &other) {
            throw RuntimeException("Arrays do not support '==' operations.");
        }

        bool ArrayValue::operator!=(const Value &other) {
            throw RuntimeException("Arrays do not support '!=' operations.");
        }

        bool ArrayValue::operator<(const Value &other) {
            throw RuntimeException("Arrays do not support '<' operations.");
        }

        bool ArrayValue::operator<=(const Value &other) {
            throw RuntimeException("Arrays do not support '<=' operations.");
        }

        bool ArrayValue::operator>(const Value &other) {
            throw RuntimeException("Arrays do not support '>' operations.");
        }

        bool ArrayValue::operator>=(const Value &other) {
            throw RuntimeException("Arrays do not support '>=' operations.");
        }

        Value *ArrayValue::operator[](const int index) {
            return mValues.at(index);
        }

        Value *ArrayValue::operator()() {
            throw RuntimeException("Arrays do not support '()' operations.");
        }
    }
}
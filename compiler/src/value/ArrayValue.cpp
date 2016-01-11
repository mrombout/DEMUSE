#include <sstream>
#include "exception/RuntimeException.h"
#include "value/NumberValue.h"
#include "value/ArrayValue.h"

namespace dem {
    namespace compiler {
        ArrayValue::ArrayValue(std::vector<Variable*> values) :
            mValues(values) {
            mProperties["length"] = new Variable(new parser::Identifier("length"), new NumberValue(mValues.size()));
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

        Variable *ArrayValue::operator[](const std::string &index) {
            throw RuntimeException("Arrays do not support '.' operations.");
        }

        Value *ArrayValue::operator()() {
            throw RuntimeException("Arrays do not support '()' operations.");
        }
    }
}
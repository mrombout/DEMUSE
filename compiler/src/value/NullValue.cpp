#include <typeinfo>
#include "exception/RuntimeException.h"
#include "value/NullValue.h"

namespace dem {
    namespace compiler {
        Value *NullValue::add(Value *b) {
            throw RuntimeException("Null does not support addition operations.");
        }

        Value *NullValue::subtract(Value *b) {
            throw RuntimeException("Null does not support subtraction operations.");
        }

        Value *NullValue::multiply(Value *b) {
            throw RuntimeException("Null does not support multiplication operations.");
        }

        Value *NullValue::divide(Value *b) {
            throw RuntimeException("Null does not support division operations.");
        }

        Value *NullValue::modulo(Value *b) {
            throw RuntimeException("Null does not support modulo operations.");
        }

        Value *NullValue::exponent(Value *b) {
            throw RuntimeException("Null does not support exponent operations.");
        }

        double NullValue::asNumber() const {
            throw RuntimeException("Value of type 'Null' can not implicitly be converted to value of type 'Number'.");
        }

        bool NullValue::asBool() const {
            throw RuntimeException("Value of type 'Null' can not implicitly be converted to value of type 'Boolean'.");
        }

        std::string NullValue::asString() const {
            return "NULL";
        }

        parser::Note NullValue::asNote() const {
            throw RuntimeException("Value of type 'Null' can not implicitly be converted to value of type 'Note'.");
        }

        bool NullValue::operator==(const Value &other) {
            throw RuntimeException("Null does not support '==' operations.");
        }

        bool NullValue::operator!=(const Value &other) {
            throw RuntimeException("Null does not support '!=' operations.");
        }

        bool NullValue::operator<(const Value &other) {
            throw RuntimeException("Null does not support '<' operations.");
        }

        bool NullValue::operator<=(const Value &other) {
            throw RuntimeException("Null does not support '<=' operations.");
        }

        bool NullValue::operator>(const Value &other) {
            throw RuntimeException("Null does not support '>' operations.");
        }

        bool NullValue::operator>=(const Value &other) {
            throw RuntimeException("Null does not support '>=' operations.");
        }

        Value *NullValue::operator[](const int index) {
            throw RuntimeException("Null does not support '[]' operations.");
        }

        Variable *NullValue::operator[](const std::string &index) {
            throw RuntimeException("Null does not support '.' operations.");
        }

        Value *NullValue::operator()(Scope &scope) {
            throw RuntimeException("Null does not support '()' operations.");
        }
    }
}

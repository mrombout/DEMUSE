#include <typeinfo>
#include "value/NullValue.h"

namespace dem {
    namespace compiler {
        std::string NullValue::toString() {
            return "NULL";
        }

        Value *NullValue::add(Value *b) {
            throw "NullValue"; // TODO: Throw proper exception
        }

        Value *NullValue::subtract(Value *b) {
            throw "NullValue"; // TODO: Throw proper exception
        }

        Value *NullValue::multiply(Value *b) {
            throw "NullValue"; // TODO: Throw proper exception
        }

        Value *NullValue::divide(Value *b) {
            throw "NullValue"; // TODO: Throw proper exception
        }

        Value *NullValue::modulo(Value *b) {
            throw "NullValue"; // TODO: Throw proper exception
        }

        double NullValue::asNumber() const {
            throw "NullValue"; // TODO: Throw proper exception
        }

        bool NullValue::asBool() const {
            throw "NullValue"; // TODO: Throw proper exception
        }

        bool NullValue::operator==(const Value &other) {
            return typeid(dem::compiler::NullValue).name() == typeid(other).name(); // TODO: Does this work?
        }
    }
}

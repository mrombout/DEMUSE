#include <value/NullValue.h>
#include "value/ObjectValue.h"

namespace dem {
    namespace compiler {
        Variable *ObjectValue::operator[](const std::string &index) {
            if(mProperties.count(index) == 0) {
                mProperties[index] = new Variable(new parser::Identifier(index), new NullValue());
            }
            return mProperties.at(index);
        }

        Value *ObjectValue::add(Value *b) {
            throw "Not implemented";
        }

        Value *ObjectValue::subtract(Value *b) {
            throw "Not implemented";
        }

        Value *ObjectValue::multiply(Value *b) {
            throw "Not implemented";
        }

        Value *ObjectValue::divide(Value *b) {
            throw "Not implemented";
        }

        Value *ObjectValue::modulo(Value *b) {
            throw "Not implemented";
        }

        Value *ObjectValue::exponent(Value *b) {
            throw "Not implemented";
        }

        double ObjectValue::asNumber() const {
            throw "Not implemented";
        }

        bool ObjectValue::asBool() const {
            throw "Not implemented";
        }

        std::string ObjectValue::asString() const {
            return "Object";
        }

        parser::Note ObjectValue::asNote() const {
            throw "Not implemented"; // TODO: Throw proper error
        }

        bool ObjectValue::operator==(const Value &other) {
            throw "Not implemented";
        }

        bool ObjectValue::operator!=(const Value &other) {
            throw "Not implemented";
        }

        bool ObjectValue::operator<(const Value &other) {
            throw "Not implemented";
        }

        bool ObjectValue::operator<=(const Value &other) {
            throw "Not implemented";
        }

        bool ObjectValue::operator>(const Value &other) {
            throw "Not implemented";
        }

        bool ObjectValue::operator>=(const Value &other) {
            throw "Not implemented";
        }

        Value *ObjectValue::operator[](const int index) {
            throw "Not implemented";
        }
    }
}

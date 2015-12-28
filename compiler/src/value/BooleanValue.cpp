#include "value/BooleanValue.h"

namespace dem {
    namespace compiler {
        BooleanValue::BooleanValue(bool value) :
            mValue(value) {

        }

        Value *BooleanValue::add(Value *b) {
            throw "Can not add booleans"; // TODO: Throw proper error
        }

        Value *BooleanValue::subtract(Value *b) {
            throw "Can not subtract booleans"; // TODO: Throw proper error
        }

        Value *BooleanValue::multiply(Value *b) {
            throw "Can not subtract booleans"; // TODO: Throw proper error
        }

        Value *BooleanValue::divide(Value *b) {
            throw "Can not subtract booleans"; // TODO: Throw proper error
        }

        Value *BooleanValue::modulo(Value *b) {
            throw "Can not subtract booleans"; // TODO: Throw proper error
        }

        Value *BooleanValue::exponent(Value *b) {
            throw "Can not subtract booleans"; // TODO: Throw proper error
        }

        double BooleanValue::asNumber() const {
            return mValue ? 1 : 0;
        }

        bool BooleanValue::asBool() const {
            return mValue;
        }

        std::string BooleanValue::asString() const {
            return mValue ? "true" : "false";
        }

        parser::Note BooleanValue::asNote() const {
            throw "Can't cast to note"; // TODO: Throw proper error
        }

        bool BooleanValue::operator==(const Value &other) {
            return mValue == other.asBool();
        }

        bool BooleanValue::operator!=(const Value &other) {
            return mValue != other.asBool();
        }

        bool BooleanValue::operator<(const Value &other) {
            return mValue < other.asBool();
        }

        bool BooleanValue::operator<=(const Value &other) {
            return mValue <= other.asBool();
        }

        bool BooleanValue::operator>(const Value &other) {
            return mValue > other.asBool();
        }

        bool BooleanValue::operator>=(const Value &other) {
            return mValue >= other.asBool();
        }

        Value *BooleanValue::operator[](const int index) {
            throw "Can not access boolean that way"; // TODO: Throw proper error
        }

        Variable *BooleanValue::operator[](const std::string &index) {
            throw "Can not access boolean that way"; // TODO: Throw proper error
        }

        Value *BooleanValue::operator()(Scope &scope) {
            throw "Can not call boolean";
        }
    }
}
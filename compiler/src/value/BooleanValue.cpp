#include "exception/RuntimeException.h"
#include "value/BooleanValue.h"

namespace dem {
    namespace compiler {
        BooleanValue::BooleanValue(bool value) :
            mValue(value) {

        }

        Value *BooleanValue::add(Value *b) {
            throw RuntimeException("Booleans do not support addition operations.");
        }

        Value *BooleanValue::subtract(Value *b) {
            throw RuntimeException("Booleans do not support subtraction operations.");
        }

        Value *BooleanValue::multiply(Value *b) {
            throw RuntimeException("Booleans do not support multiplication operations.");
        }

        Value *BooleanValue::divide(Value *b) {
            throw RuntimeException("Booleans do not support divisions operations.");
        }

        Value *BooleanValue::modulo(Value *b) {
            throw RuntimeException("Booleans do not support modulo operations.");
        }

        Value *BooleanValue::exponent(Value *b) {
            throw RuntimeException("Booleans do not support exponent operations.");
        }

        Value *BooleanValue::value() {
            return new BooleanValue(*this);
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
            throw RuntimeException("Value of type 'Boolean' can not implicitly be converted to value of type 'Note'.");
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
            throw RuntimeException("Booleans do not support '[]' operations.");
        }

        Variable *BooleanValue::operator[](const std::string &index) {
            throw RuntimeException("Booleans do not support '.' operations.");
        }

        Value *BooleanValue::operator()() {
            throw RuntimeException("Booleans do not support '()' operations.");
        }
    }
}
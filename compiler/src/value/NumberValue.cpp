#include <math.h>
#include <exception/RuntimeException.h>
#include "value/NumberValue.h"

namespace dem {
    namespace compiler {
        NumberValue::NumberValue(double value) :
            mValue(value) {

        }

        Value *NumberValue::add(Value *b) {
            double newValue = mValue + b->asNumber();

            return new NumberValue(newValue);
        }

        Value *NumberValue::subtract(Value *b) {
            double newValue = mValue - b->asNumber();

            return new NumberValue(newValue);
        }

        Value *NumberValue::multiply(Value *b) {
            double newValue = mValue * b->asNumber();

            return new NumberValue(newValue);
        }

        Value *NumberValue::divide(Value *b) {
            double newValue = mValue / b->asNumber();

            return new NumberValue(newValue);
        }

        Value *NumberValue::modulo(Value *b) {
            double newValue = fmod(mValue, b->asNumber());

            return new NumberValue(newValue);
        }

        Value *NumberValue::exponent(Value *b) {
            double newValue = pow(mValue, b->asNumber());

            return new NumberValue(newValue);
        }

        Value *NumberValue::value() {
            return new NumberValue(*this);
        }

        double NumberValue::asNumber() const {
            return mValue;
        }

        bool NumberValue::asBool() const {
            return mValue > 0;
        }

        std::string NumberValue::asString() const {
            return std::to_string(mValue);
        }

        parser::Note NumberValue::asNote() const {
            throw RuntimeException("Value of type 'Number' can not implicitly be converted to value of type 'Note'.");
        }

        bool NumberValue::operator==(const Value &other) {
            return mValue == other.asNumber();
        }

        bool NumberValue::operator!=(const Value &other) {
            return mValue != other.asNumber();
        }

        bool NumberValue::operator<(const Value &other) {
            return mValue < other.asNumber();
        }

        bool NumberValue::operator<=(const Value &other) {
            return mValue <= other.asNumber();
        }

        bool NumberValue::operator>(const Value &other) {
            return mValue > other.asNumber();
        }

        bool NumberValue::operator>=(const Value &other) {
            return mValue >= other.asNumber();
        }

        Value *NumberValue::operator[](const int index) {
            throw RuntimeException("Numbers do not support '[]' operations.");
        }

        Variable *NumberValue::operator[](const std::string &index) {
            throw RuntimeException("Numbers do not support '.' operations.");
        }

        Value *NumberValue::operator()(ObjectValue &scope) {
            throw RuntimeException("Numbers do not support '()' operations.");
        }
    }
}

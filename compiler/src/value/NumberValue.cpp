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

        double NumberValue::asNumber() const {
            return mValue;
        }

        bool NumberValue::asBool() const {
            return mValue > 0;
        }

        std::string NumberValue::asString() const {
            return std::to_string(mValue);
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
            throw "Can not access that way"; // TODO: Throw proper error
        }

        Variable *NumberValue::operator[](const std::string &index) {
            throw "Can not access that way"; // TODO: Throw proper error
        }

        Value *NumberValue::operator()(Scope &scope) {
            throw "Can not call number";
        }
    }
}

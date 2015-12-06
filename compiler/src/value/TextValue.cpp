#include "value/Value.h"
#include "value/TextValue.h"

namespace dem {
    namespace compiler {
        TextValue::TextValue(std::string value) :
            mValue(value) {

        }

        Value *TextValue::add(Value *b) {
            std::string newValue = mValue + b->asString();

            return new TextValue(newValue);
        }

        Value *TextValue::subtract(Value *b) {
            throw "Can't subtract from text"; // TODO: Throw proper error
        }

        Value *TextValue::multiply(Value *b) {
            throw "Can't multiply text"; // TODO: Throw proper error
        }

        Value *TextValue::divide(Value *b) {
            throw "Can't divide text"; // TODO: Throw proper error
        }

        Value *TextValue::modulo(Value *b) {
            throw "Can't modulo tex"; // TODO: Throw proper error
        }

        Value *TextValue::exponent(Value *b) {
            throw "Can't modulo tex"; // TODO: Throw proper error
        }

        double TextValue::asNumber() const {
            return std::stod(mValue);
        }

        bool TextValue::asBool() const {
            return !mValue.empty();
        }

        std::string TextValue::asString() const {
            return mValue;
        }

        bool TextValue::operator==(const Value &other) {
            return mValue == other.asString();
        }

        bool TextValue::operator!=(const Value &other) {
            return mValue != other.asString();
        }

        bool TextValue::operator<(const Value &other) {
            return mValue < other.asString();
        }

        bool TextValue::operator<=(const Value &other) {
            return mValue <= other.asString();
        }

        bool TextValue::operator>(const Value &other) {
            return mValue > other.asString();
        }

        bool TextValue::operator>=(const Value &other) {
            return mValue >= other.asString();
        }

        Value *TextValue::operator[](const int index) {
            return new TextValue(std::to_string(mValue.at(index)));
        }
    }
}

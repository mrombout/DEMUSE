#include <value/function/InternalLambdaFunction.h>
#include "exception/RuntimeException.h"
#include "value/Value.h"
#include "value/TextValue.h"
#include "value/NumberValue.h"
#include "value/Variable.h"

namespace dem {
    namespace compiler {
        TextValue::TextValue(std::string value) :
            mValue(value) {
            mProperties["length"] = new Variable(new parser::Identifier("length"), new NumberValue(value.length()));
            mProperties["charAt"] = new Variable(new parser::Identifier("charAt"), new InternalLambdaFunction(this, [this](InternalLambdaFunction &function, ObjectValue &objectValue) -> Value* {
                return new TextValue(std::string(1, mValue.at(objectValue.variable(new parser::Identifier("1"))->asNumber())));
            }));
            mProperties["charCodeAt"] = new Variable(new parser::Identifier("charCodeAt"), new InternalLambdaFunction(this, [this](InternalLambdaFunction &function, ObjectValue &objectValue) -> Value* {
                return new NumberValue(mValue.at(objectValue.variable(new parser::Identifier("1"))->asNumber()));
            }));
        }

        Value *TextValue::add(Value *b) {
            std::string newValue = mValue + b->asString();

            return new TextValue(newValue);
        }

        Value *TextValue::subtract(Value *b) {
            throw RuntimeException("Strings do not support subtraction operations.");
        }

        Value *TextValue::multiply(Value *b) {
            throw RuntimeException("Strings do not support multiplication operations.");
        }

        Value *TextValue::divide(Value *b) {
            throw RuntimeException("Strings do not support division operations.");
        }

        Value *TextValue::modulo(Value *b) {
            throw RuntimeException("Strings do not support modulo operations.");
        }

        Value *TextValue::exponent(Value *b) {
            throw RuntimeException("Strings do not support exponent operations.");
        }

        Value *TextValue::value() {
            return new TextValue(*this);
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

        parser::Note TextValue::asNote() const {
            throw RuntimeException("Value of type 'Text' can not implicitly be converted to value of type 'Note'.");
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
            return new TextValue(std::string(1, mValue.at(index)));
        }

        Variable *TextValue::operator[](const std::string &index) {
            return ObjectValue::operator[](index);
        }

        Value *TextValue::operator()(ObjectValue &scope) {
            throw RuntimeException("Strings do not support '()' operations.");
        }
    }
}

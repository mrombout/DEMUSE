#include "exception/RuntimeException.h"
#include "value/Value.h"
#include "value/TextValue.h"
#include "value/NumberValue.h"

namespace dem {
    namespace compiler {
        TextValue::TextValue(std::string value) :
            mValue(value) {
            mProperties["length"] = new Variable(new parser::Identifier(lexer::Token(lexer::TokenType::IDENTIFIER, "length", lexer::TokenPosition()), "length"), new NumberValue(value.length()));
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
            return new TextValue(std::to_string(mValue.at(index)));
        }

        Value *TextValue::operator()() {
            throw RuntimeException("Strings do not support '()' operations.");
        }
    }
}

#include "value/Variable.h"

namespace dem {
    namespace compiler {
        Variable::Variable(parser::Identifier *identifier, Value *value) :
            mIdentifier(identifier),
            mValue(value) {

        }

        parser::Identifier *Variable::identifier() const {
            return mIdentifier;
        }

        Value *Variable::value() const {
            return mValue;
        }

        void Variable::setValue(Value *value) {
            mValue = value;
        }

        Value *Variable::add(Value *b) {
            return mValue->add(b);
        }

        Value *Variable::subtract(Value *b) {
            return mValue->subtract(b);
        }

        Value *Variable::multiply(Value *b) {
            return mValue->multiply(b);
        }

        Value *Variable::divide(Value *b) {
            return mValue->divide(b);
        }

        Value *Variable::modulo(Value *b) {
            return mValue->modulo(b);
        }

        Value *Variable::exponent(Value *b) {
            return mValue->exponent(b);
        }

        double Variable::asNumber() const {
            return mValue->asNumber();
        }

        bool Variable::asBool() const {
            return mValue->asBool();
        }

        std::string Variable::asString() const {
            return mValue->asString();
        }

        bool Variable::operator==(const Value &other) {
            return *mValue == other;
        }

        bool Variable::operator!=(const Value &other) {
            return *mValue != other;
        }

        bool Variable::operator<(const Value &other) {
            return *mValue < other;
        }

        bool Variable::operator<=(const Value &other) {
            return *mValue <= other;
        }

        bool Variable::operator>(const Value &other) {
            return *mValue > other;
        }

        bool Variable::operator>=(const Value &other) {
            return *mValue >= other;
        }

        Value *Variable::operator[](const int index) {
            return (*mValue)[index];
        }

        Value *Variable::operator[](const std::string &index) {
            return (*mValue)[index];
        }

        Value *Variable::operator()(Scope &scope) {
            return (*mValue)(scope);
        }
    }
}

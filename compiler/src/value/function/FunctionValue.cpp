#include "exception/RuntimeException.h"
#include "value/Value.h"
#include "value/function/FunctionValue.h"

namespace dem {
    namespace compiler {
        Value *FunctionValue::add(Value *b) {
            throw "Can't add"; // TODO: Throw proper error
        }

        Value *FunctionValue::subtract(Value *b) {
            throw "Can't subtract"; // TODO: Throw proper error
        }

        Value *FunctionValue::multiply(Value *b) {
            throw "Can't multiply"; // TODO: Throw proper error
        }

        Value *FunctionValue::divide(Value *b) {
            throw "Can't divide"; // TODO: Throw proper error
        }

        Value *FunctionValue::modulo(Value *b) {
            throw "Can't modulo"; // TODO: Throw proper error
        }

        Value *FunctionValue::exponent(Value *b) {
            throw "Can't exponent"; // TODO: Throw proper error
        }

        std::string FunctionValue::asString() const {
            return "function(){ ... }";
        }

        double FunctionValue::asNumber() const {
            throw "Can't number"; // TODO: Throw proper error
        }

        bool FunctionValue::asBool() const {
            throw "Can't bool"; // TODO: Throw proper error
        }

        bool FunctionValue::operator==(const Value &other) {
            throw "Error"; // TODO: Throw proper error
        }

        bool FunctionValue::operator!=(const Value &other) {
            throw "Error"; // TODO: Throw proper error
        }

        bool FunctionValue::operator<(const Value &other) {
            throw "Error"; // TODO: Throw proper error
        }

        bool FunctionValue::operator<=(const Value &other) {
            throw "Error"; // TODO: Throw proper error
        }

        bool FunctionValue::operator>(const Value &other) {
            throw "Error"; // TODO: Throw proper error
        }

        bool FunctionValue::operator>=(const Value &other) {
            throw "Error"; // TODO: Throw proper error
        }

        Value *FunctionValue::operator[](const int index) {
            throw "Error"; // TODO: Throw proper error
        }
    }
}

#include <sstream>
#include <exception/RuntimeException.h>
#include "value/ArrayValue.h"

namespace dem {
    namespace compiler {
        ArrayValue::ArrayValue(std::vector<Value *> values) :
            mValues(values) {

        }

        Value *dem::compiler::ArrayValue::add(Value *b) {
            return nullptr;
        }

        Value *dem::compiler::ArrayValue::subtract(Value *b) {
            return nullptr;
        }

        Value *dem::compiler::ArrayValue::multiply(Value *b) {
            return nullptr;
        }

        Value *dem::compiler::ArrayValue::divide(Value *b) {
            return nullptr;
        }

        Value *dem::compiler::ArrayValue::modulo(Value *b) {
            return nullptr;
        }

        Value *dem::compiler::ArrayValue::exponent(Value *b) {
            return nullptr;
        }

        double ArrayValue::asNumber() const {
            return 0;
        }

        bool ArrayValue::asBool() const {
            return false;
        }

        std::string ArrayValue::asString() const {
            std::stringstream ss;
            ss << "[";

            for(Value *value : mValues) {
                ss << value->asString() << ", ";
                // TODO: Remove last comma in array string
            }

            ss << "]";

            return ss.str();
        }

        bool ArrayValue::operator==(const Value &other) {
            return false;
        }

        bool ArrayValue::operator!=(const Value &other) {
            return false;
        }

        bool ArrayValue::operator<(const Value &other) {
            return false;
        }

        bool ArrayValue::operator<=(const Value &other) {
            return false;
        }

        bool ArrayValue::operator>(const Value &other) {
            return false;
        }

        bool ArrayValue::operator>=(const Value &other) {
            return false;
        }

        Value *ArrayValue::operator[](const int index) {
            return mValues.at(index);
        }

        Value *ArrayValue::operator[](const std::string &index) {
            throw "Index must be Number."; // TODO: Throw proper error
        }

        Value *ArrayValue::operator()(Scope &scope) {
            throw "Can not call array.";
        }
    }
}
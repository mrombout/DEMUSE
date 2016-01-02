#include "exception/RuntimeException.h"
#include "value/NullValue.h"
#include "value/ObjectValue.h"
#include "value/Property.h"

namespace dem {
    namespace compiler {
        ObjectValue::ObjectValue() :
            ObjectValue(nullptr) {

        }

        ObjectValue::ObjectValue(ObjectValue* parent) :
            mParent(parent) {

        }

        Variable *ObjectValue::operator[](const std::string &index) {
            if(mProperties.count(index) == 0) {
                mProperties[index] = new Property(this, new parser::Identifier(lexer::Token(lexer::TokenType::IDENTIFIER, index, lexer::TokenPosition()), index), new NullValue());
            }
            return mProperties.at(index);
        }

        std::string ObjectValue::asString() const {
            return "Object";
        }

        Value *ObjectValue::add(Value *b) {
            throw RuntimeException("Objects do not support addition operations.");
        }

        Value *ObjectValue::subtract(Value *b) {
            throw RuntimeException("Objects do not support subtraction operations.");
        }

        Value *ObjectValue::multiply(Value *b) {
            throw RuntimeException("Objects do not support multiplication operations.");
        }

        Value *ObjectValue::divide(Value *b) {
            throw RuntimeException("Objects do not support division operations.");
        }

        Value *ObjectValue::modulo(Value *b) {
            throw RuntimeException("Objects do not support modulo operations.");
        }

        Value *ObjectValue::exponent(Value *b) {
            throw RuntimeException("Objects do not support exponent operations.");
        }

        double ObjectValue::asNumber() const {
            throw RuntimeException("Value of type 'Object' can not implicitly be converted to value of type 'Number'.");
        }

        bool ObjectValue::asBool() const {
            throw RuntimeException("Value of type 'Object' can not implicitly be converted to value of type 'Boolean'.");
        }

        parser::Note ObjectValue::asNote() const {
            throw RuntimeException("Value of type 'Object' can not implicitly be converted to value of type 'Note'.");
        }

        bool ObjectValue::operator==(const Value &other) {
            throw RuntimeException("Objects do not support '==' operations.");
        }

        bool ObjectValue::operator!=(const Value &other) {
            throw RuntimeException("Objects do not support '!=' operations.");
        }

        bool ObjectValue::operator<(const Value &other) {
            throw RuntimeException("Objects do not support '<' operations.");
        }

        bool ObjectValue::operator<=(const Value &other) {
            throw RuntimeException("Objects do not support '<=' operations.");
        }

        bool ObjectValue::operator>(const Value &other) {
            throw RuntimeException("Objects do not support '>' operations.");
        }

        bool ObjectValue::operator>=(const Value &other) {
            throw RuntimeException("Objects do not support '>=' operations.");
        }

        Value *ObjectValue::operator[](const int index) {
            throw RuntimeException("Objects do not support '[]' operations.");
        }

        void ObjectValue::declareVariable(parser::Identifier *identifier) {
            declareVariable(identifier, new NullValue());
        }

        void ObjectValue::declareVariable(parser::Identifier *identifier, Value *value) {
            std::clog << "DECLARE - Variable " << identifier->name() << " = " << value->asString() << std::endl;

            mProperties[identifier->name()] = new Variable(identifier, value);
        }

        Variable &ObjectValue::variable(parser::Identifier *identifier) const {
            try {
                Variable *variable = mProperties.at(identifier->name());

                return *variable;
            } catch(std::out_of_range &e) {
                if(mParent)
                    return mParent->variable(identifier);
                throw RuntimeException(identifier->token(), "Variable '" + identifier->name() + "' does not exist.");
            }
        }

        ObjectValue *ObjectValue::parent() const {
            return mParent;
        }

        void ObjectValue::setParent(ObjectValue *parent) {
            mParent = parent;
        }
    }
}

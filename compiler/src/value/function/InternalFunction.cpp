#include <vector>
#include "exception/RuntimeException.h"
#include "value/function/InternalFunction.h"

namespace dem {
    namespace compiler {
        InternalFunction::InternalFunction(ObjectValue *parent) :
            FunctionValue(parent) {

        }

        void InternalFunction::mapScope(ObjectValue &functionScope, std::vector<Value*> &arguments) {
            int curIndex = 0;
            for(Value *value : arguments) {
                std::string name = std::to_string(++curIndex);
                functionScope.declareVariable(new parser::Identifier(lexer::Token(lexer::TokenType::IDENTIFIER, name, lexer::TokenPosition()), name), value);
            }
        }

        Value *InternalFunction::add(Value *b) {
            throw RuntimeException("Functions do not support addition operations.");
        }

        Value *InternalFunction::subtract(Value *b) {
            throw RuntimeException("Functions do not support subtraction operations.");
        }

        Value *InternalFunction::multiply(Value *b) {
            throw RuntimeException("Functions do not support multiplication operations.");
        }

        Value *InternalFunction::divide(Value *b) {
            throw RuntimeException("Functions do not support division operations.");
        }

        Value *InternalFunction::modulo(Value *b) {
            throw RuntimeException("Functions do not support modulo operations.");
        }

        Value *InternalFunction::exponent(Value *b) {
            throw RuntimeException("Functions do not support exponent operations.");
        }

        double InternalFunction::asNumber() const {
            throw RuntimeException("Value of type 'Function' can not implicitly be converted to value of type 'Number'.");
        }

        bool InternalFunction::asBool() const {
            throw RuntimeException("Value of type 'Function' can not implicitly be converted to value of type 'Boolean'.");
        }

        parser::Note InternalFunction::asNote() const {
            throw RuntimeException("Value of type 'Function' can not implicitly be converted to value of type 'Note'.");
        }

        bool InternalFunction::operator==(const Value &other) {
            throw RuntimeException("Functions do not support '==' operations.");
        }

        bool InternalFunction::operator!=(const Value &other) {
            throw RuntimeException("Functions do not support '!=' operations.");
        }

        bool InternalFunction::operator<(const Value &other) {
            throw RuntimeException("Functions do not support '<' operations.");
        }

        bool InternalFunction::operator<=(const Value &other) {
            throw RuntimeException("Functions do not support '<=' operations.");
        }

        bool InternalFunction::operator>(const Value &other) {
            throw RuntimeException("Functions do not support '>' operations.");
        }

        bool InternalFunction::operator>=(const Value &other) {
            throw RuntimeException("Functions do not support '>=' operations.");
        }

        Value *InternalFunction::operator[](const int index) {
            throw RuntimeException("Functions do not support '[]' operations.");
        }
    }
}

#ifndef DEMUSE_VALUE_H
#define DEMUSE_VALUE_H

#include <string>
#include <typeinfo>
#include "symbol/play/Note.h"

namespace dem {
    namespace compiler {
        class Variable;
    }
}

namespace dem {
    namespace compiler {
        class Value {
        public:
            virtual ~Value() { }

            virtual Value *add(Value *b) = 0;
            virtual Value *subtract(Value *b) = 0;
            virtual Value *multiply(Value *b) = 0;
            virtual Value *divide(Value *b) = 0;
            virtual Value *modulo(Value *b) = 0;
            virtual Value *exponent(Value *b) = 0;

            virtual double asNumber() const = 0;
            virtual bool asBool() const = 0;
            virtual std::string asString() const = 0;
            virtual parser::Note asNote() const = 0;

            virtual bool operator==(const Value &other) = 0;
            virtual bool operator!=(const Value &other) = 0;
            virtual bool operator<(const Value &other) = 0;
            virtual bool operator<=(const Value &other) = 0;
            virtual bool operator>(const Value &other) = 0;
            virtual bool operator>=(const Value &other) = 0;
            virtual Value *operator[](const int index) = 0;
            virtual Variable *operator[](const std::string &index) = 0;

            virtual Value * operator()();

            virtual bool strictEqual(const Value &other) {
                if(typeid(*this).name() != typeid(other).name())
                    return false;
                return *this == other;
            }

            virtual bool strictNotEqual(const Value &other) {
                if(typeid(*this).name() != typeid(other).name())
                    return true;
                return *this != other;
            }
        };
    }
}

#endif //DEMUSE_VALUE_H

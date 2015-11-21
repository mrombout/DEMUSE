#ifndef DEMUSE_VALUE_H
#define DEMUSE_VALUE_H

#include <string>

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

            virtual double asNumber() const = 0;
            virtual bool asBool() const = 0;

            virtual std::string toString() = 0;

            virtual bool operator==(const Value &other) = 0;
            virtual bool operator!=(const Value &other) = 0;
        };
    }
}

#endif //DEMUSE_VALUE_H

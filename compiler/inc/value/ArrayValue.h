#ifndef DEMUSE_ARRAYVALUE_H
#define DEMUSE_ARRAYVALUE_H

#include <vector>
#include "value/Value.h"

namespace dem {
    namespace compiler {
        class ArrayValue : public Value {
        public:
            ArrayValue(std::vector<Value*> values);

            virtual Value *add(Value *b);
            virtual Value *subtract(Value *b);
            virtual Value *multiply(Value *b);
            virtual Value *divide(Value *b);
            virtual Value *modulo(Value *b);
            virtual Value *exponent(Value *b);

            virtual double asNumber() const;
            virtual bool asBool() const;
            virtual std::string asString() const;

            virtual bool operator==(const Value &other);
            virtual bool operator!=(const Value &other);
            virtual bool operator<(const Value &other);
            virtual bool operator<=(const Value &other);
            virtual bool operator>(const Value &other);
            virtual bool operator>=(const Value &other);
            virtual Value *operator[](const int index);

        private:
            std::vector<Value*> mValues;
        };
    }
}

#endif //DEMUSE_ARRAYVALUE_H

#ifndef DEMUSE_NULLVALUE_H
#define DEMUSE_NULLVALUE_H

#include "Value.h"

namespace dem {
    namespace compiler {
        class NullValue : public Value {
        public:
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
        };
    }
}

#endif //DEMUSE_NULLVALUE_H

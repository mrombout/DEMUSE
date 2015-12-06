#ifndef DEMUSE_BOOLEANVALUE_H
#define DEMUSE_BOOLEANVALUE_H

#include <string>
#include "Value.h"

namespace dem {
    namespace compiler {
        class BooleanValue : public Value {
        public:
            BooleanValue(bool value);

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
            virtual Value *operator[](const std::string &index);
            virtual Value *operator()(Scope &scope);

        private:
            bool mValue;
        };
    }
}

#endif //DEMUSE_BOOLEANVALUE_H

#ifndef DEMUSE_NUMBERVALUE_H
#define DEMUSE_NUMBERVALUE_H

#include "Value.h"

namespace dem {
    namespace compiler {
        class NumberValue : public Value {
        public:
            NumberValue(double value);

            virtual Value *add(Value *b);
            virtual Value *subtract(Value *b);
            virtual Value *multiply(Value *b);
            virtual Value *divide(Value *b);
            virtual Value *modulo(Value *b);
            virtual Value *exponent(Value *b);

            virtual double asNumber() const;
            virtual bool asBool() const;
            virtual std::string asString() const;


            virtual parser::Note asNote() const;

            virtual bool operator==(const Value &other);
            virtual bool operator!=(const Value &other);
            virtual bool operator<(const Value &other);
            virtual bool operator<=(const Value &other);
            virtual bool operator>(const Value &other);
            virtual bool operator>=(const Value &other);
            virtual Value *operator[](const int index) override;
            virtual Variable *operator[](const std::string &index);
            virtual Value *operator()(Scope &scope);

        private:
            double mValue;
        };
    }
}

#endif //DEMUSE_NUMBERVALUE_H

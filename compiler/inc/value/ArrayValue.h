#ifndef DEMUSE_ARRAYVALUE_H
#define DEMUSE_ARRAYVALUE_H

#include <vector>
#include "value/Value.h"
#include "ObjectValue.h"

namespace dem {
    namespace compiler {
        class ArrayValue : public ObjectValue {
        public:
            ArrayValue(std::vector<Variable*> values);

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
            virtual Value *operator[](const int index);
            virtual Variable *operator[](const std::string &index);
            virtual Value *operator()();

        private:
            std::vector<Variable*> mValues;
        };
    }
}

#endif //DEMUSE_ARRAYVALUE_H

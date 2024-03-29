#ifndef DEMUSE_NULLVALUE_H
#define DEMUSE_NULLVALUE_H

#include "Value.h"

namespace dem {
    namespace compiler {
        /**
         * \brief Represents a null value
         */
        class NullValue : public Value {
        public:
            virtual Value *add(Value *b);
            virtual Value *subtract(Value *b);
            virtual Value *multiply(Value *b);
            virtual Value *divide(Value *b);
            virtual Value *modulo(Value *b);
            virtual Value *exponent(Value *b);

            virtual Value *value();
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
            virtual Value *operator()(ObjectValue &scope);
        };
    }
}

#endif //DEMUSE_NULLVALUE_H

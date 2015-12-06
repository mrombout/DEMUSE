#ifndef DEMUSE_VARIABLE_H
#define DEMUSE_VARIABLE_H

#include "symbol/Identifier.h"
#include "value/Value.h"

namespace dem {
    namespace compiler {
        class Variable : public Value {
        public:
            Variable(parser::Identifier *identifier, Value *value);

            parser::Identifier *identifier() const;

            Value *value() const;
            void setValue(Value *value);

            virtual Value *add(Value *b);
            virtual Value *multiply(Value *b);
            virtual Value *subtract(Value *b);
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
            parser::Identifier *mIdentifier;
            Value *mValue;
        };
    }
}

#endif //DEMUSE_VARIABLE_H

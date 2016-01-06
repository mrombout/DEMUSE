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

            virtual void setValue(Value *value);

            Value *realValue() const;

            virtual Value *add(Value *b);
            virtual Value *multiply(Value *b);
            virtual Value *subtract(Value *b);
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

            virtual bool strictEqual(const Value &other) override;
            virtual bool strictNotEqual(const Value &other) override;

        private:
            parser::Identifier *mIdentifier;
            Value *mValue;
        };
    }
}

#endif //DEMUSE_VARIABLE_H

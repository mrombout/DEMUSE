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

            virtual double asNumber() const;
            virtual bool asBool() const;

            virtual std::string toString();

            virtual bool operator==(const Value &other);

        private:
            parser::Identifier *mIdentifier;
            Value *mValue;
        };
    }
}

#endif //DEMUSE_VARIABLE_H

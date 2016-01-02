#ifndef DEMUSE_INTERNALFUNCTION_H
#define DEMUSE_INTERNALFUNCTION_H

#include "value/function/FunctionValue.h"
#include "value/Value.h"

namespace dem {
    namespace compiler {
        class InternalFunction : public FunctionValue {
        public:
            InternalFunction(ObjectValue *parent);

            virtual Value *add(Value *b);
            virtual Value *subtract(Value *b);
            virtual Value *multiply(Value *b);
            virtual Value *divide(Value *b);
            virtual Value *modulo(Value *b);
            virtual Value *exponent(Value *b);

            virtual double asNumber() const;
            virtual bool asBool() const;
            virtual parser::Note asNote() const;

            virtual bool operator==(const Value &other);
            virtual bool operator!=(const Value &other);
            virtual bool operator<(const Value &other);
            virtual bool operator<=(const Value &other);
            virtual bool operator>(const Value &other);
            virtual bool operator>=(const Value &other);
            virtual Value *operator[](const int index);

            virtual void mapScope(std::vector<Value*> &arguments);
        };
    }
}

#endif //DEMUSE_INTERNALFUNCTION_H

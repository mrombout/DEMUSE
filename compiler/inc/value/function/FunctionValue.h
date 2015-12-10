#ifndef DEMUSE_FUNCTIONVALUE_H
#define DEMUSE_FUNCTIONVALUE_H

#include "value/ObjectValue.h"
#include "symbol/ParameterList.h"
#include "symbol/Block.h"
#include "Compiler.h"

namespace dem {
    namespace compiler {
        class FunctionValue : public ObjectValue {
        public:
            virtual Value *add(Value *b);
            virtual Value *subtract(Value *b);
            virtual Value *multiply(Value *b);
            virtual Value *divide(Value *b);
            virtual Value *modulo(Value *b);
            virtual Value *exponent(Value *b);

            virtual std::string asString() const;
            virtual double asNumber() const;
            virtual bool asBool() const;

            virtual bool operator==(const Value &other);
            virtual bool operator!=(const Value &other);
            virtual bool operator<(const Value &other);
            virtual bool operator<=(const Value &other);
            virtual bool operator>(const Value &other);
            virtual bool operator>=(const Value &other);
            virtual Value *operator[](const int index);

            virtual void mapScope(Scope &scope, std::vector<Value*> &arguments) = 0;
        };
    }
}

#endif //DEMUSE_FUNCTIONVALUE_H

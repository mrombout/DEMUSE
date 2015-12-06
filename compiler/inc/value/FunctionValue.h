#ifndef DEMUSE_FUNCTIONVALUE_H
#define DEMUSE_FUNCTIONVALUE_H

#include "ObjectValue.h"
#include "symbol/ParameterList.h"
#include "symbol/Block.h"
#include "Compiler.h"

namespace dem {
    namespace compiler {
        class FunctionValue : public ObjectValue {
        public:
            FunctionValue(Compiler &compiler, parser::ParameterList &parameterList, parser::Block &block);

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

            void mapScope(Scope &scope, std::vector<Value*> &arguments);
            virtual Value *operator()(Scope &scope);

        private:
            Compiler &mCompiler;
            parser::ParameterList &mParameterList;
            parser::Block &mBlock;
        };
    }
}

#endif //DEMUSE_FUNCTIONVALUE_H

#ifndef DEMUSE_USERFUNCTION_H
#define DEMUSE_USERFUNCTION_H

#include "Compiler.h"
#include "FunctionValue.h"

namespace dem {
    namespace compiler {
        class UserFunction : public FunctionValue {
        public:
            UserFunction(Compiler &compiler, parser::ParameterList &parameterList, parser::Block &block);


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

            virtual Variable *operator[](const std::string &index);

            void mapScope(Scope &scope, std::vector<Value*> &arguments) override;
            virtual Value *operator()(Scope &scope);

        private:
            Compiler &mCompiler;
            parser::ParameterList &mParameterList;
            parser::Block &mBlock;
        };
    }
}

#endif //DEMUSE_USERFUNCTION_H

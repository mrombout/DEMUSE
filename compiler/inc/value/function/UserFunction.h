#ifndef DEMUSE_USERFUNCTION_H
#define DEMUSE_USERFUNCTION_H

#include "Compiler.h"
#include "FunctionValue.h"

namespace dem {
    namespace compiler {
        /**
         * \brief Represents a function declared in DEMUSE script (e.g. a function defined by the user)
         */
        class UserFunction : public FunctionValue {
        public:
            UserFunction(Compiler &compiler, parser::ParameterList &parameterList, parser::Block &block);
            UserFunction(Compiler &compiler, ObjectValue *parent, parser::ParameterList &parameterList, parser::Block &block);

            virtual Value *add(Value *b);
            virtual Value *subtract(Value *b);
            virtual Value *multiply(Value *b);
            virtual Value *divide(Value *b);
            virtual Value *modulo(Value *b);
            virtual Value *exponent(Value *b);

            virtual double asNumber() const;
            virtual bool asBool() const;
            virtual parser::Note asNote() const;
            virtual std::string asString() const override;

            virtual bool operator==(const Value &other);
            virtual bool operator!=(const Value &other);
            virtual bool operator<(const Value &other);
            virtual bool operator<=(const Value &other);
            virtual bool operator>(const Value &other);
            virtual bool operator>=(const Value &other);

            virtual Value *operator[](const int index);
            virtual Variable *operator[](const std::string &index);

            void mapScope(ObjectValue &functionScope, std::vector<Value*> &arguments) override;
            virtual Value *operator()(ObjectValue &scope);

        private:
            Compiler &mCompiler;
            parser::ParameterList &mParameterList;
            parser::Block &mBlock;
        };
    }
}

#endif //DEMUSE_USERFUNCTION_H

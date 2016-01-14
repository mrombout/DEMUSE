#ifndef DEMUSE_OBJECTVALUE_H
#define DEMUSE_OBJECTVALUE_H

#include <map>
#include "Value.h"
#include "symbol/Identifier.h"

namespace dem {
    namespace compiler {
        class Variable;
    }
}

namespace dem {
    namespace compiler {
        /**
         * \brief Represents an object value
         */
        class ObjectValue : public Value {
        public:
            ObjectValue();
            ObjectValue(ObjectValue* parent);

            virtual Value *add(Value *b);
            virtual Value *subtract(Value *b);
            virtual Value *multiply(Value *b);
            virtual Value *divide(Value *b);
            virtual Value *modulo(Value *b);
            virtual Value *exponent(Value *b);

            virtual Value *value();
            virtual double asNumber() const;
            virtual bool asBool() const;
            virtual parser::Note asNote() const;
            virtual std::string asString() const;

            virtual bool operator==(const Value &other);
            virtual bool operator!=(const Value &other);
            virtual bool operator<(const Value &other);
            virtual bool operator<=(const Value &other);
            virtual bool operator>(const Value &other);
            virtual bool operator>=(const Value &other);

            virtual Value *operator[](const int index);
            virtual Variable *operator[](const std::string &index);
            virtual Value *operator()(ObjectValue &scope);

            void declareVariable(parser::Identifier *identifier);
            void declareVariable(parser::Identifier *identifier, Value *value);

            Variable *variable(parser::Identifier *identifier) const;

            ObjectValue *parent() const;
            void setParent(ObjectValue *parent);

        protected:
            ObjectValue *mParent;
            std::map<std::string, Variable*> mProperties;
        };
    }
}

#endif //DEMUSE_OBJECTVALUE_H

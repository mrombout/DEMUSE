#ifndef DEMUSE_OBJECTVALUE_H
#define DEMUSE_OBJECTVALUE_H

#include <map>
#include "value/Variable.h"

namespace dem {
    namespace compiler {
        class ObjectValue : public Value {
        public:
            virtual Value *add(Value *b);
            virtual Value *subtract(Value *b);
            virtual Value *multiply(Value *b);
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

        protected:
            std::map<std::string, Variable*> mProperties;
        };
    }
}

#endif //DEMUSE_OBJECTVALUE_H

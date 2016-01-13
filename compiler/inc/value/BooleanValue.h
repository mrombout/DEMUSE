#ifndef DEMUSE_BOOLEANVALUE_H
#define DEMUSE_BOOLEANVALUE_H

#include <string>
#include "Value.h"
#include "ObjectValue.h"

namespace dem {
    namespace compiler {
        /**
         * \brief Represents a boolean value
         */
        class BooleanValue : public ObjectValue {
        public:
            BooleanValue(bool value);

            virtual Value *add(Value *b);
            virtual Value *subtract(Value *b);
            virtual Value *multiply(Value *b);
            virtual Value *divide(Value *b);
            virtual Value *modulo(Value *b);
            virtual Value *exponent(Value *b);


            virtual Value *value();

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
            virtual Value *operator()(ObjectValue &scope);

        private:
            bool mValue;
        };
    }
}

#endif //DEMUSE_BOOLEANVALUE_H

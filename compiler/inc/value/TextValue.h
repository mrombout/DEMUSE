#ifndef DEMUSE_TEXTVALUE_H
#define DEMUSE_TEXTVALUE_H

#include <string>
#include "Value.h"
#include "ObjectValue.h"

namespace dem {
    namespace compiler {
        class TextValue : public ObjectValue {
        public:
            TextValue(std::string value);

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
            virtual Value *operator()(Scope &scope);

        private:
            std::string mValue;
        };
    }
}

#endif //DEMUSE_TEXTVALUE_H

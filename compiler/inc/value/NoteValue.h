#ifndef DEMUSE_NOTEVALUE_H
#define DEMUSE_NOTEVALUE_H

#include "symbol/play/Note.h"
#include "Value.h"
#include "ObjectValue.h"

namespace dem {
    namespace compiler {
        /**
         * \brief Represents a note value
         */
        class NoteValue : public ObjectValue {
        public:
            NoteValue(parser::Note note);

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
            parser::Note mNote;
        };
    }
}

#endif //DEMUSE_NOTEVALUE_H

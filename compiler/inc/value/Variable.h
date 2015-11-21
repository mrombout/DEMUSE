#ifndef DEMUSE_VARIABLE_H
#define DEMUSE_VARIABLE_H

#include "symbol/Identifier.h"
#include "value/Value.h"

namespace dem {
    namespace compiler {
        class Variable : public Value {
        public:
            Variable(parser::Identifier *identifier, Value *value);

            parser::Identifier *identifier() const;

            Value *value() const;

            virtual std::string toString();

            void setValue(Value *value);

        private:
            parser::Identifier *mIdentifier;
            Value *mValue;
        };
    }
}

#endif //DEMUSE_VARIABLE_H

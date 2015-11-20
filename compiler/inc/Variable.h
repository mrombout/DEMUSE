#ifndef DEMUSE_VARIABLE_H
#define DEMUSE_VARIABLE_H

#include "symbol/Identifier.h"
#include "value/Value.h"

namespace dem {
    namespace compiler {
        class Variable {
        public:
            Variable(parser::Identifier *identifier, Value *value);

            parser::Identifier *identifier() const;
            Value *value() const;

        private:
            parser::Identifier *mIdentifier;
            Value *mValue;
        };
    }
}

#endif //DEMUSE_VARIABLE_H

#ifndef DEMUSE_PROPERTY_H
#define DEMUSE_PROPERTY_H

#include "value/Variable.h"
#include "ObjectValue.h"

namespace dem {
    namespace compiler {
        /**
         * \brief Represents a property of an object
         */
        class Property : public Variable {
        public:
            Property(ObjectValue *parent, parser::Identifier *identifier, Value *value);

            virtual void setValue(Value *value) override;

        private:
            ObjectValue *mParent;
        };
    }
}

#endif //DEMUSE_PROPERTY_H

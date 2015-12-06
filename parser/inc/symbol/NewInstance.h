#ifndef DEMUSE_NEWINSTANCE_H
#define DEMUSE_NEWINSTANCE_H

#include "expression/Expression.h"
#include "Identifier.h"

namespace dem {
    namespace parser {
        class NewInstance : public Expression {
        public:
            NewInstance(Identifier *identifier);

            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_NEWINSTANCE_H

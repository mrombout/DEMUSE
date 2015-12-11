#ifndef DEMUSE_NEWINSTANCE_H
#define DEMUSE_NEWINSTANCE_H

#include "expression/Expression.h"
#include "Identifier.h"
#include "ArgumentList.h"

namespace dem {
    namespace parser {
        class NewInstance : public Expression {
        public:
            NewInstance(Identifier *identifier, ArgumentList *argumentList);

            virtual bool accept(Visitor &visitor);

        private:
            Identifier *mIdentifier;
            ArgumentList *mArgumentList;
        };
    }
}

#endif //DEMUSE_NEWINSTANCE_H

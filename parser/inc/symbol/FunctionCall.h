#ifndef DEMUSE_FUNCTIONCALL_H
#define DEMUSE_FUNCTIONCALL_H

#include "ProcedureCall.h"
#include "Identifier.h"
#include "ArgumentList.h"

namespace dem {
    namespace parser {
        class FunctionCall : public ProcedureCall {
        public:
            FunctionCall(Identifier *identifier);
            FunctionCall(Identifier *identifier, ArgumentList *argumentList);

            virtual bool accept(Visitor &visitor);

            Identifier &identifier() const;
            ArgumentList *argumentList() const;

        private:
            Identifier *mIdentifier;
            ArgumentList *mArgumentList;
        };
    }
}


#endif //DEMUSE_FUNCTIONCALL_H

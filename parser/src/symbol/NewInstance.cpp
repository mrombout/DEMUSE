#include "symbol/NewInstance.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        NewInstance::NewInstance(Identifier *identifier, ArgumentList *argumentList) :
            Expression(identifier->token()),
            mIdentifier(identifier),
            mArgumentList(argumentList) {

        }

        bool NewInstance::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                mIdentifier->accept(visitor);
                mArgumentList->accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}

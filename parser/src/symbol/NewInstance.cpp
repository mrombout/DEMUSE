#include <stdexcept>
#include "symbol/NewInstance.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        NewInstance::NewInstance(Identifier *identifier, ArgumentList *argumentList) :
            Expression(identifier->token()),
            mIdentifier(identifier),
            mArgumentList(argumentList) {
            if(!mIdentifier)
                throw std::invalid_argument("Argument 'identifier' may not be null.");
            if(!mArgumentList)
                throw std::invalid_argument("Argument 'argumentList' may not be null.");
        }

        NewInstance::~NewInstance() {
            delete mIdentifier;
            delete mArgumentList;
        }

        bool NewInstance::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                mIdentifier->accept(visitor);
                mArgumentList->accept(visitor);
            }

            return visitor.visitLeave(*this);
        }

        const Identifier &NewInstance::identifier() const {
            return *mIdentifier;
        }

        const ArgumentList &NewInstance::argumentList() const {
            return *mArgumentList;
        }
    }
}

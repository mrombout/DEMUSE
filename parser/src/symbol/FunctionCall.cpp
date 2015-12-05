#include "symbol/FunctionCall.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        FunctionCall::FunctionCall(Identifier *identifier) :
            FunctionCall(identifier, nullptr) { // TODO: Add default constructor for ArgumentList

        }

        FunctionCall::FunctionCall(Identifier *identifier, ArgumentList *argumentList) :
            mIdentifier(identifier),
            mArgumentList(argumentList) {
            if(!argumentList)
                mArgumentList = new ArgumentList(std::vector<Expression*>());
        }

        bool FunctionCall::accept(Visitor &visitor) {
            visitor.visit(*this);
        }

        Identifier &FunctionCall::identifier() const {
            return *mIdentifier;
        }

        ArgumentList *FunctionCall::argumentList() const {
            return mArgumentList;
        }
    }
}

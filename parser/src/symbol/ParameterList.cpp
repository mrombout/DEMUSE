#include "symbol/ParameterList.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        ParameterList::ParameterList() {

        }

        ParameterList::ParameterList(std::vector<Identifier*> identifiers) :
            mIdentifiers(identifiers) {

        }

        bool ParameterList::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                for(Identifier *identifier : mIdentifiers) {
                    identifier->accept(visitor);
                }
            }

            return visitor.visitLeave(*this);
        }

        std::vector<Identifier *> ParameterList::parameters() const {
            return mIdentifiers;
        }

        int ParameterList::numParameters() const {
            return mIdentifiers.size();
        }

        bool ParameterList::isEmpty() const {
            return mIdentifiers.empty();
        }
    }
}

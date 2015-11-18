#include "symbol/ParameterList.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
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
    }
}

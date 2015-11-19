#include "symbol/FunctionDefinition.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        bool FunctionDefinition::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                // TODO: visit children
            }

            return visitor.visitLeave(*this);
        }
    }
}

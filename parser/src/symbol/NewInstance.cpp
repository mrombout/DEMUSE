#include "symbol/NewInstance.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        bool NewInstance::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {

            }

            return visitor.visitLeave(*this);
        }
    }
}

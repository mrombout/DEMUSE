#include "symbol/play/Play.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        bool Play::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                // TODO: Visit children
            }

            return visitor.visitLeave(*this);
        }
    }
}

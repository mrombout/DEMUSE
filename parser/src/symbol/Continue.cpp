#include "symbol/Continue.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        bool Continue::accept(Visitor &visitor) {
            visitor.visit(*this);
        }
    }
}

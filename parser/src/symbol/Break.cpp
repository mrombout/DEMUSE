#include "symbol/Break.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        bool Break::accept(Visitor &visitor) {
            visitor.visit(*this);
        }
    }
}

#include "symbol/play/Note.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        bool Note::accept(Visitor &visitor) {
            return visitor.visit(*this);
        }
    }
}

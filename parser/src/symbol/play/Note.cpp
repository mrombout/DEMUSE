#include "symbol/play/Note.h"

namespace dem {
    namespace parser {
        bool Note::accept(Visitor &visitor) {
            return visitor.visit(*this);
        }
    }
}

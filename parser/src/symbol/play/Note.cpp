#include "symbol/play/Note.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Note::Note() {

        }

        bool Note::accept(Visitor &visitor) {
            return visitor.visit(*this);
        }
    }
}

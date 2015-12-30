#include "symbol/Continue.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Continue::Continue(const lexer::Token &token) :
                Statement(token) {

        }

        bool Continue::accept(Visitor &visitor) {
            return visitor.visit(*this);
        }
    }
}

#include "symbol/Break.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Break::Break(const lexer::Token &token) :
                Statement(token) {

        }

        bool Break::accept(Visitor &visitor) {
            visitor.visit(*this);
        }
    }
}

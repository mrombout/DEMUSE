#include "symbol/expression/BoolLiteral.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        BoolLiteral::BoolLiteral(const lexer::Token &token, bool value) :
            Literal(token),
            mValue(value) {

        }

        bool BoolLiteral::value() const {
            return mValue;
        }

        bool BoolLiteral::accept(Visitor &visitor) {
            return visitor.visit(*this);
        }
    }
}

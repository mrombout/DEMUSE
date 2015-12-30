#include "symbol/expression/NumberLiteral.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        NumberLiteral::NumberLiteral(lexer::Token &token, double value) :
            Literal(token),
            mValue(value) {

        }

        double NumberLiteral::value() const {
            return mValue;
        }

        bool NumberLiteral::accept(Visitor &visitor) {
            visitor.visit(*this);
        }
    }
}

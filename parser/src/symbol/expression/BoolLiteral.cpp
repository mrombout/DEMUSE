#include "symbol/expression/BoolLiteral.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        BoolLiteral::BoolLiteral(bool value) :
            mValue(value) {

        }

        bool BoolLiteral::value() const {
            return mValue;
        }

        bool BoolLiteral::accept(Visitor &visitor) {
            visitor.visit(*this);
        }
    }
}

#include "symbol/Number.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Number::Number(double value) :
            mValue(value) {

        }

        double Number::value() const {
            return mValue;
        }

        bool Number::accept(Visitor &visitor) {
            visitor.visit(*this);
        }
    }
}

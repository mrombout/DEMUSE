#include "symbol/Number.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Number::Number(std::string value) :
            mValue(value) {

        }

        std::string Number::value() const {
            return mValue;
        }

        bool Number::accept(Visitor &visitor) {
            visitor.visit(*this);
        }
    }
}

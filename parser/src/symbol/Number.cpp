#include "symbol/Number.h"

namespace dem {
    namespace parser {
        Number::Number(std::string value) :
            mValue(value) {

        }

        std::string Number::value() const {
            return mValue;
        }
    }
}

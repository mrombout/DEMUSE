#include "value/NumberValue.h"

namespace dem {
    namespace compiler {
        NumberValue::NumberValue(double value) :
            mValue(value) {

        }

        std::string NumberValue::toString() {
            return std::to_string(mValue);
        }
    }
}

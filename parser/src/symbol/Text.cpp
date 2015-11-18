#include "symbol/Text.h"

namespace dem {
    namespace parser {
        Text::Text(std::string value) :
            mValue(value) {

        }

        std::string Text::value() const {
            return mValue;
        }
    }
}

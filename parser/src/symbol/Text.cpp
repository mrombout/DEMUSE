#include "symbol/Text.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Text::Text(std::string value) :
            mValue(value) {

        }

        std::string Text::value() const {
            return mValue;
        }

        bool Text::accept(Visitor &visitor) {
            visitor.visit(*this);
        }
    }
}

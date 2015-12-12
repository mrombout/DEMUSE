#include "symbol/expression/TextLiteral.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        TextLiteral::TextLiteral(std::string value) :
            mValue(value) {

        }

        std::string TextLiteral::value() const {
            return mValue;
        }

        bool TextLiteral::accept(Visitor &visitor) {
            visitor.visit(*this);
        }
    }
}

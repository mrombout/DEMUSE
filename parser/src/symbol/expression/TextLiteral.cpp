#include "symbol/expression/TextLiteral.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        TextLiteral::TextLiteral(const lexer::Token &token, std::string value) :
            Literal(token),
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

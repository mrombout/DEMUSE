#include "symbol/Identifier.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Identifier::Identifier(const std::string &name) :
                Identifier(lexer::Token(lexer::TokenType::IDENTIFIER, "length", lexer::TokenPosition()), name) {

        }

        Identifier::Identifier(const lexer::Token &token, std::string name) :
            Expression(token),
            mName(name) {

        }

        bool Identifier::accept(Visitor &visitor) {
            return visitor.visit(*this);
        }

        const std::string &Identifier::name() const {
            return mName;
        }
    }
}

#include "symbol/Symbol.h"

namespace dem {
    namespace parser {
        Symbol::Symbol(const lexer::Token token) :
            mToken(token) {

        }

        Symbol::~Symbol() {

        }

        const lexer::Token &Symbol::token() const {
            return mToken;
        }
    }
}

#include "symbol/expression/Literal.h"

namespace dem {
    namespace parser {
        Literal::Literal(const lexer::Token &token) :
                Expression(token) {

        }
    }
}
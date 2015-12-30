#include "symbol/expression/Expression.h"

namespace dem {
    namespace parser {
        Expression::Expression(const lexer::Token &token) :
                CompoundStatement(token) {

        }
    }
}
#include "symbol/Statement.h"

namespace dem {
    namespace parser {
        Statement::Statement(const lexer::Token &token) :
                Symbol(token) {

        }

        Statement::~Statement() {

        }
    }
}
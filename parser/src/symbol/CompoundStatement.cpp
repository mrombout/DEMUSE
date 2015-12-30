#include "symbol/CompoundStatement.h"

namespace dem {
    namespace parser {
        CompoundStatement::CompoundStatement(const lexer::Token &token) :
                Statement(token) {

        }
    }
}
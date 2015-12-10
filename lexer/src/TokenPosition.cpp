#include "TokenPosition.h"

namespace dem {
    namespace lexer {
        TokenPosition::TokenPosition() :
            TokenPosition(1, 1, 0) {

        }

        TokenPosition::TokenPosition(unsigned int line, unsigned int column, unsigned int index) :
            line(line),
            column(column),
            index(index) {

        }
    }
}

#include "symbol/While.h"

namespace dem {
    namespace parser {
        While::While(Expression *expression, Block *block) :
            mExpression(expression),
            mBlock(block) {

        }
    }
}

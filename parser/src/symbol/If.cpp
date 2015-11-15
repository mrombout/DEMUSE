#include "symbol/If.h"

namespace dem {
    namespace parser {
        If::If(Expression *expression, Block *block) :
            If(expression, block, nullptr) {

        }

        If::If(Expression *expression, Block *block, Block *elseBlock) :
                mExpression(expression),
                mBlock(block),
                mElseBlock(elseBlock) {

        }
    }
}

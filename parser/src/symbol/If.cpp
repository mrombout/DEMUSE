#include "symbol/If.h"
#include "Visitor.h"

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

        bool If::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                mExpression->accept(visitor);
                mBlock->accept(visitor);
                if(mElseBlock) {
                    mElseBlock->accept(visitor);
                }
            }

            return visitor.visitLeave(*this);
        }
    }
}

#include "Visitor.h"

namespace dem {
    namespace parser {
        While::While(Expression *expression, Block *block) :
            CompoundStatement(expression->token()),
            mExpression(expression),
            mBlock(block) {

        }

        bool While::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                mExpression->accept(visitor);
                mBlock->accept(visitor);
            }

            return visitor.visitLeave(*this);
        }

        Expression &While::expression() const {
            return *mExpression;
        }

        Block &While::block() const {
            return *mBlock;
        }
    }
}

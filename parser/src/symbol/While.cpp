#include <stdexcept>
#include "Visitor.h"

namespace dem {
    namespace parser {
        While::While(Expression *expression, Block *block) :
            CompoundStatement(expression->token()),
            mExpression(expression),
            mBlock(block) {
            if(!mExpression)
                throw std::invalid_argument("Argument 'expression' may not be null.");
            if(!mBlock)
                throw std::invalid_argument("Argument 'block' may not be null.");
        }

        While::~While() {
            delete mExpression;
            delete mBlock;
        }

        bool While::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                if(mExpression->accept(visitor))
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

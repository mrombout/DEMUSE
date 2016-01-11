#include <stdexcept>
#include "symbol/For.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        For::For(Statement *initialization, Expression *condition, AssignmentExpression *afterThought, Block *block) :
            CompoundStatement(initialization->token()),
            mInitialization(initialization),
            mCondition(condition),
            mAfterThought(afterThought),
            mBlock(block) {
            if(!mBlock)
                throw std::invalid_argument("Argument 'block' may not be null.");
        }

        bool For::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                mInitialization->accept(visitor);
                mCondition->accept(visitor);
                mAfterThought->accept(visitor);
            }

            return visitor.visitLeave(*this);
        }

        Statement *For::initialization() const {
            return mInitialization;
        }

        Expression *For::condition() const {
            return mCondition;
        }

        AssignmentExpression *For::afterThought() const {
            return mAfterThought;
        }

        Block &For::block() const {
            return *mBlock;
        }

        For::~For() {
            if(mInitialization)
                delete mInitialization;
            if(mCondition)
                delete mCondition;
            if(mAfterThought)
                delete mAfterThought;
            if(mBlock)
                delete mBlock;
        }
    }
}

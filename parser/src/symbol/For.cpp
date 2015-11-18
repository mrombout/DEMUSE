#include "symbol/For.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        For::For(Statement *initialization, Expression *condition, Assignment *afterThought) :
            mInitialization(initialization),
            mCondition(condition),
            mAfterThought(afterThought) {

        }

        bool For::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                mInitialization->accept(visitor);
                mCondition->accept(visitor);
                mAfterThought->accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}

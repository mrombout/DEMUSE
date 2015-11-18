#include "symbol/For.h"

namespace dem {
    namespace parser {
        For::For(Statement *initialization, Expression *condition, Assignment *afterThought) :
            mInitialization(initialization),
            mCondition(condition),
            mAfterThought(afterThought) {

        }
    }
}

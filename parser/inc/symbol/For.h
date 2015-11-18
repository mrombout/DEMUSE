#ifndef DEMUSE_FOR_H
#define DEMUSE_FOR_H

#include "Statement.h"
#include "symbol/expression/Expression.h"
#include "symbol/Assignment.h"

namespace dem {
    namespace parser {
        class For : public Statement {
        public:
            For(Statement *initialization, Expression *condition, Assignment *afterThought);

        private:
            Statement *mInitialization;
            Expression *mCondition;
            Assignment *mAfterThought;
        };
    }
}

#endif //DEMUSE_FOR_H

#ifndef DEMUSE_ANDCONDITION_H
#define DEMUSE_ANDCONDITION_H

#include "Condition.h"

namespace dem {
    namespace parser {
        class AndCondition : public Condition {
        public:
            AndCondition(Expression *left, Expression *right);
        };
    }
}

#endif //DEMUSE_ANDCONDITION_H

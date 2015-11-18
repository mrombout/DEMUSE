#ifndef DEMUSE_STRICTEQUALCONDITION_H
#define DEMUSE_STRICTEQUALCONDITION_H

#include "Condition.h"

namespace dem {
    namespace parser {
        class StrictEqualCondition : public Condition {
        public:
            StrictEqualCondition(Expression *left, Expression *right);
        };
    }
}

#endif //DEMUSE_STRICTEQUALCONDITION_H

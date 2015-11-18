#ifndef DEMUSE_LARGERTHANOREQUALCONDITION_H
#define DEMUSE_LARGERTHANOREQUALCONDITION_H

#include "Condition.h"

namespace dem {
    namespace parser {
        class LargerThanOrEqualCondition : public Condition {
        public:
            LargerThanOrEqualCondition(Expression *left, Expression *right);
        };
    }
}

#endif //DEMUSE_LARGERTHANOREQUALCONDITION_H

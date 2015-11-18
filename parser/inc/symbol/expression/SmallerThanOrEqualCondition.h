#ifndef DEMUSE_SMALLERTHANOREQUAL_H
#define DEMUSE_SMALLERTHANOREQUAL_H

#include "Condition.h"

namespace dem {
    namespace parser {
        class SmallerThanOrEqualCondition : public Condition {
        public:
            SmallerThanOrEqualCondition(Expression *left, Expression *right);
        };
    }
}

#endif //DEMUSE_SMALLERTHANOREQUAL_H

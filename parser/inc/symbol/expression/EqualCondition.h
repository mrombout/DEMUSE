#ifndef DEMUSE_EQUALCONDITION_H
#define DEMUSE_EQUALCONDITION_H

#include "Condition.h"

namespace dem {
    namespace parser {
        class EqualCondition : public Condition {
        public:
            EqualCondition(Expression *left, Expression *right);
        };
    }
}

#endif //DEMUSE_EQUALCONDITION_H

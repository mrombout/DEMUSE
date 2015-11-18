#ifndef DEMUSE_NOTEQUALCONDITION_H
#define DEMUSE_NOTEQUALCONDITION_H

#include "Condition.h"

namespace dem {
    namespace parser {
        class NotEqualCondition : public Condition {
        public:
            NotEqualCondition(Expression *left, Expression *right);
        };
    }
}

#endif //DEMUSE_NOTEQUALCONDITION_H

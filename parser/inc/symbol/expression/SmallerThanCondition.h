#ifndef DEMUSE_SMALLERCONDITION_H
#define DEMUSE_SMALLERCONDITION_H

#include "Condition.h"

namespace dem {
    namespace parser {
        class SmallerThanCondition : public Condition {
        public:
            SmallerThanCondition(Expression *left, Expression *right);

            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_SMALLERCONDITION_H

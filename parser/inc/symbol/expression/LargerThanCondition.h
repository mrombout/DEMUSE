#ifndef DEMUSE_LARGERTHANCONDITION_H
#define DEMUSE_LARGERTHANCONDITION_H

#include "Condition.h"

namespace dem {
    namespace parser {
        class LargerThanCondition : public Condition {
        public:
            LargerThanCondition(Expression *left, Expression *right);

            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_LARGERTHANCONDITION_H

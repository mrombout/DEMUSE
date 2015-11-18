#ifndef DEMUSE_NOTEQUALCONDITION_H
#define DEMUSE_NOTEQUALCONDITION_H

#include "Condition.h"

namespace dem {
    namespace parser {
        class NotEqualCondition : public Condition {
        public:
            NotEqualCondition(Expression *left, Expression *right);

            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_NOTEQUALCONDITION_H

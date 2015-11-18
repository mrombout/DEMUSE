#ifndef DEMUSE_ORCONDITION_H
#define DEMUSE_ORCONDITION_H

#include "Condition.h"

namespace dem {
    namespace parser {
        class OrCondition : public Condition {
        public:
            OrCondition(Expression *left, Expression *right);

            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_ORCONDITION_H

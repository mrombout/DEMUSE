#ifndef DEMUSE_STRICTEQUALCONDITION_H
#define DEMUSE_STRICTEQUALCONDITION_H

#include "Condition.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents a strict equal condition (e.g. 1 === 1)
         */
        class StrictEqualCondition : public Condition {
        public:
            StrictEqualCondition(Expression *left, Expression *right);

            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_STRICTEQUALCONDITION_H

#ifndef DEMUSE_LARGERTHANOREQUALCONDITION_H
#define DEMUSE_LARGERTHANOREQUALCONDITION_H

#include "Condition.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents a larger than or equal condition (e.g. 5 >= 5)
         */
        class LargerThanOrEqualCondition : public Condition {
        public:
            LargerThanOrEqualCondition(Expression *left, Expression *right);

            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_LARGERTHANOREQUALCONDITION_H

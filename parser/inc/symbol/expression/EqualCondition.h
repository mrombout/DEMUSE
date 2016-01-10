#ifndef DEMUSE_EQUALCONDITION_H
#define DEMUSE_EQUALCONDITION_H

#include "Condition.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents an equal condition (e.g. 1 == 1)
         */
        class EqualCondition : public Condition {
        public:
            virtual bool accept(Visitor &visitor);

            EqualCondition(Expression *left, Expression *right);
        };
    }
}

#endif //DEMUSE_EQUALCONDITION_H

#ifndef DEMUSE_STRICTNOTEQUALCONDITION_H
#define DEMUSE_STRICTNOTEQUALCONDITION_H

#include "Condition.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents a strict not equal condition (e.g. 1 !== "1")
         */
        class StrictNotEqualCondition : public Condition {
        public:
            StrictNotEqualCondition(Expression *left, Expression *right);

            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_STRICTNOTEQUALCONDITION_H

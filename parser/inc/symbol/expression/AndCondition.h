#ifndef DEMUSE_ANDCONDITION_H
#define DEMUSE_ANDCONDITION_H

#include "Condition.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents an and condition (e.g. true && false)
         */
        class AndCondition : public Condition {
        public:
            AndCondition(Expression *left, Expression *right);

            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_ANDCONDITION_H

#ifndef DEMUSE_STRICTNOTEQUALCONDITION_H
#define DEMUSE_STRICTNOTEQUALCONDITION_H

#include "Condition.h"

namespace dem {
    namespace parser {
        class StrictNotEqualCondition : public Condition {
        public:
            StrictNotEqualCondition(Expression *left, Expression *right);
        };
    }
}

#endif //DEMUSE_STRICTNOTEQUALCONDITION_H

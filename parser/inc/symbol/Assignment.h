#ifndef DEMUSE_ASSIGNMENT_H
#define DEMUSE_ASSIGNMENT_H

#include "Statement.h"
#include "Identifier.h"
#include "Expression.h"

namespace dem {
    namespace parser {
        class Assignment : public Statement {
        public:
            Assignment(Identifier *identifier, Expression *expression);

        private:
            Identifier *mIdentifier;
            Expression *mExpression;
        };
    }
}

#endif //DEMUSE_ASSIGNMENT_H

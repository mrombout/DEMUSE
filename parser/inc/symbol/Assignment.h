#ifndef DEMUSE_ASSIGNMENT_H
#define DEMUSE_ASSIGNMENT_H

#include "Statement.h"
#include "Identifier.h"
#include "expression/Expression.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents an assignment (e.g. a = 4)
         */
        class Assignment : public Statement {
        public:
            Assignment(Identifier *identifier, Expression *expression);

            Identifier &identifier() const;
            Expression &expression() const;

        private:
            Identifier *mIdentifier;
            Expression *mExpression;
        public:
            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_ASSIGNMENT_H

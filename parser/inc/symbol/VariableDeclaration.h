#ifndef DEMUSE_VARIABLEDECLARATION_H
#define DEMUSE_VARIABLEDECLARATION_H

#include <symbol/expression/AssignmentExpression.h>
#include "Statement.h"
#include "symbol/Assignment.h"

namespace dem {
    namespace parser {
        class Assignment;
    }
}

namespace dem {
    namespace parser {
        /**
         * \brief Represents a variable declaration (e.g. var A = 4;
         */
        class VariableDeclaration : public Statement {
        public:
            VariableDeclaration(AssignmentExpression *assignment);
            virtual ~VariableDeclaration();

            virtual bool accept(Visitor &visitor);

            AssignmentExpression &assignment() const;

        private:
            AssignmentExpression *mAssignment;
        };
    }
}

#endif //DEMUSE_VARIABLEDECLARATION_H

#ifndef DEMUSE_VARIABLEDEFINITION_H
#define DEMUSE_VARIABLEDEFINITION_H

#include "Statement.h"
#include "symbol/VariableDefinition.h"
#include "symbol/Assignment.h"

namespace dem {
    namespace parser {
        class VariableDefinition : public Statement {
        public:
            VariableDefinition(Assignment *assignment);


            virtual ~VariableDefinition();

        private:
            Assignment *mAssignment;
        };
    }
}

#endif //DEMUSE_VARIABLEDEFINITION_H

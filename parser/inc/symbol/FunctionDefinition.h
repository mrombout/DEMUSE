#ifndef DEMUSE_FUNCTIONDEFINITION_H
#define DEMUSE_FUNCTIONDEFINITION_H

#include "Statement.h"

namespace dem {
    namespace parser {
        class FunctionDefinition : public Statement {
        public:
            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_FUNCTIONDEFINITION_H

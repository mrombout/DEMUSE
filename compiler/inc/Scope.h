#ifndef DEMUSE_SCOPE_H
#define DEMUSE_SCOPE_H

#include <string>
#include <map>
#include "symbol/Identifier.h"
#include "Variable.h"

namespace dem {
    namespace compiler {
        class Scope {
        public:
            Scope(Scope *parent);

            void declareVariable(parser::Identifier *identifier);

        private:
            Scope *mParent;
            std::map<parser::Identifier*, Variable*> mVariables;
        };
    }
}

#endif //DEMUSE_SCOPE_H

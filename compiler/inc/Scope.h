#ifndef DEMUSE_SCOPE_H
#define DEMUSE_SCOPE_H

#include <string>
#include <map>
#include "symbol/Identifier.h"
#include "value/Variable.h"
#include "function/Function.h"

namespace dem {
    namespace compiler {
        class Scope {
        public:
            Scope(Scope *parent);

            void declareVariable(parser::Identifier *identifier);
            void declareVariable(parser::Identifier *identifier, Value *value);
            void declareFunction(Function *function);

            Variable &variable(parser::Identifier *identifier) const;
            Function &function(parser::Identifier *function) const;

        private:
            Scope *mParent;
            std::map<std::string, Variable*> mVariables;
            std::map<std::string, Function*> mFunctions;
        };
    }
}

#endif //DEMUSE_SCOPE_H

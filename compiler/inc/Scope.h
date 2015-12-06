#ifndef DEMUSE_SCOPE_H
#define DEMUSE_SCOPE_H

#include <string>
#include <map>

namespace dem {
    namespace compiler {
        class Variable;
        class Value;
    }
}

namespace dem {
    namespace parser {
        class Identifier;
    }
}

namespace dem {
    namespace compiler {
        class Scope {
        public:
            Scope(Scope *parent);

            void declareVariable(parser::Identifier *identifier);
            void declareVariable(parser::Identifier *identifier, Value *value);

            Variable &variable(parser::Identifier *identifier) const;

        private:
            Scope *mParent;
            std::map<std::string, Variable*> mVariables;
        };
    }
}

#endif //DEMUSE_SCOPE_H

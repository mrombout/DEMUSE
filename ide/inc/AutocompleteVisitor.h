#ifndef DEMUSE_AUTOCOMPLETEVISITOR_H
#define DEMUSE_AUTOCOMPLETEVISITOR_H

#include <unordered_set>
#include "Visitor.h"

namespace dem {
    namespace ide {
        class AutocompleteVisitor : public parser::Visitor {
        public:
            std::unordered_set<std::string> search(parser::Symbol &symbol);

            virtual bool visitEnter(parser::FunctionDefinition &functionDefinition) override;
            virtual bool visitEnter(parser::VariableDeclaration &variableDefinition) override;

        private:
            std::unordered_set<std::string> mWords;
        };
    }
}

#endif //DEMUSE_AUTOCOMPLETEVISITOR_H

#include <iostream>
#include "AutocompleteVisitor.h"

namespace dem {
    namespace ide {
        std::unordered_set<std::string> AutocompleteVisitor::search(parser::Symbol &symbol) {
            mWords.clear();

            symbol.accept(*this);

            return mWords;
        }

        bool AutocompleteVisitor::visitEnter(parser::FunctionDefinition &functionDefinition) {
            if(functionDefinition.identifier()) {
                std::string name = functionDefinition.identifier()->name() + "?0";
                mWords.insert(name);

                std::cout << "Adding: " << name << std::endl;
            }

            return true;
        }

        bool AutocompleteVisitor::visitEnter(parser::VariableDeclaration &variableDefinition) {
            parser::Expression &lhs = variableDefinition.assignment().left();
            if(dynamic_cast<parser::Identifier*>(&lhs)) {
                parser::Identifier *identifier = static_cast<parser::Identifier*>(&lhs);
                std::string name = identifier->name();
                if(name.size() > 1) {
                    std::string name = identifier->name() + "?1";
                    mWords.insert(name);

                    std::cout << "Adding: " << name << std::endl;
                }
            }

            return true;
        }
    }
}

#include <iostream>
#include "symbol/FunctionDefinition.h"
#include "Scope.h"
#include "value/NullValue.h"
#include "function/Function.h"

namespace dem {
    namespace compiler {
        Scope::Scope(Scope *parent) :
            mParent(parent) {

        }

        void Scope::declareVariable(parser::Identifier *identifier) {
            std::cout << "DECLARE - Variable " << identifier->name() << std::endl;

            mVariables[identifier->name()] = new Variable(identifier, new NullValue());
        }

        void Scope::declareFunction(Function *function) {
            std::cout << "DECLARE - Function " << function->identifier().name() << std::endl;

            mFunctions[&function->identifier()] = function;
        }

        Variable &Scope::variable(parser::Identifier *identifier) const {
            try {
                Variable *variable = mVariables.at(identifier->name());

                return *variable;
            } catch(std::out_of_range &e) {
                if(mParent) {
                    return mParent->variable(identifier);
                } else {
                    throw "Variable does not exist"; // TODO: Proper error
                }
            }
        }
    }
}

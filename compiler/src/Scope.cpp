#include <iostream>
#include "exception/RuntimeException.h"
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
            declareVariable(identifier, new NullValue());
        }

        void Scope::declareVariable(parser::Identifier *identifier, Value *value) {
            std::cout << "DECLARE - Variable " << identifier->name() << " = " << value->asString() << std::endl;

            mVariables[identifier->name()] = new Variable(identifier, value);
        }

        void Scope::declareFunction(Function *function) {
            std::cout << "DECLARE - Function " << function->identifier().name() << std::endl;

            mFunctions[function->identifier().name()] = function;
        }

        Variable &Scope::variable(parser::Identifier *identifier) const {
            try {
                Variable *variable = mVariables.at(identifier->name());

                return *variable;
            } catch(std::out_of_range &e) {
                if(mParent)
                    return mParent->variable(identifier);
                throw RuntimeException(*identifier, "Variable '" + identifier->name() + "' does not exist.");
            }
        }

        Function &Scope::function(parser::Identifier *identifier) const {
            try {
                Function *function = mFunctions.at(identifier->name());

                return *function;
            } catch(std::out_of_range &e) {
                if(mParent)
                    return mParent->function(identifier);
                throw RuntimeException(*identifier, "Function '" + identifier->name() + "' does not exist.");
            }
        }
    }
}

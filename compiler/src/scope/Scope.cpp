#include <iostream>
#include "exception/RuntimeException.h"
#include "symbol/expression/FunctionDefinition.h"
#include "Scope.h"
#include "value/NullValue.h"
#include "value/Variable.h"

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
    }
}

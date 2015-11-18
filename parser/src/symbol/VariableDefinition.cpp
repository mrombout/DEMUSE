#include "symbol/VariableDefinition.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        VariableDefinition::VariableDefinition(Assignment *assignment) :
            mAssignment(assignment) {

        }

        VariableDefinition::~VariableDefinition() {

        }

        bool VariableDefinition::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                mAssignment->accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}

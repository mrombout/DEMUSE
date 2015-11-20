#include "symbol/VariableDeclaration.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        VariableDeclaration::VariableDeclaration(AssignmentExpression *assignment) :
            mAssignment(assignment) {

        }

        VariableDeclaration::~VariableDeclaration() {

        }

        bool VariableDeclaration::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                mAssignment->accept(visitor);
            }

            return visitor.visitLeave(*this);
        }

        AssignmentExpression &VariableDeclaration::assignment() const {
            return *mAssignment;
        }
    }
}

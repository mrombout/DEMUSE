#include <stdexcept>
#include "symbol/VariableDeclaration.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        VariableDeclaration::VariableDeclaration(AssignmentExpression *assignment) :
            Statement(assignment->token()),
            mAssignment(assignment) {
            if(!mAssignment)
                throw std::invalid_argument("Argument 'assignment' may not be null.");
        }

        VariableDeclaration::~VariableDeclaration() {
            delete mAssignment;
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

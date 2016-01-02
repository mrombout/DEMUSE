#include "symbol/expression/ThisExpression.h"
#include "Visitor.h"

namespace dem {
    namespace compiler {

    }

    bool parser::ThisExpression::accept(parser::Visitor &visitor) {
        return visitor.visit(*this);
    }
}
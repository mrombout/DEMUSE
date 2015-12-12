#include "symbol/expression/ArrayLiteral.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        ArrayLiteral::ArrayLiteral(std::vector<Expression *> values) :
            mValues(values) {

        }

        std::vector<Expression*> &ArrayLiteral::expressions() {
            return mValues;
        }

        bool ArrayLiteral::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                for(Expression *value : mValues) {
                    value->accept(visitor);
                }
            }

            return visitor.visitLeave(*this);
        }
    }
}
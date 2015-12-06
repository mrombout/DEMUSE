#include "symbol/Array.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Array::Array(std::vector<Expression *> values) :
            mValues(values) {

        }

        std::vector<Expression*> &Array::expressions() {
            return mValues;
        }

        bool Array::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                for(Expression *value : mValues) {
                    value->accept(visitor);
                }
            }

            return visitor.visitLeave(*this);
        }
    }
}
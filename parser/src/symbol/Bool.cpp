#include "symbol/Bool.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Bool::Bool(bool value) :
            mValue(value) {

        }

        bool Bool::value() const {
            return mValue;
        }

        bool Bool::accept(Visitor &visitor) {
            visitor.visit(*this);
        }
    }
}

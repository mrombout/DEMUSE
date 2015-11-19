#include "symbol/Bool.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Bool::Bool(std::string value) :
            mValue(value) {

        }

        std::string Bool::value() const {
            return mValue;
        }

        bool Bool::accept(Visitor &visitor) {
            visitor.visit(*this);
        }
    }
}

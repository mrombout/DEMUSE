#include "symbol/Bool.h"

namespace dem {
    namespace parser {
        Bool::Bool(std::string value) :
            mValue(value) {

        }

        std::string Bool::value() const {
            return mValue;
        }
    }
}

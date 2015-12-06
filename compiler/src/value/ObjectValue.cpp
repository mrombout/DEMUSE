#include "value/ObjectValue.h"

namespace dem {
    namespace compiler {
        Value *ObjectValue::operator[](const std::string &index) {
            return mProperties.at(index);
        }
    }
}

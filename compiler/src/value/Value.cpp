#include "value/ObjectValue.h"
#include "value/NullValue.h"

namespace dem {
    namespace compiler {
        Value *Value::operator()(ObjectValue &scope) {
            return new NullValue();
        }
    }
}

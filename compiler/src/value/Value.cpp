#include "value/NullValue.h"

namespace dem {
    namespace compiler {
        Value *Value::operator()(Scope &scope) {
            return new NullValue();
        }
    }
}

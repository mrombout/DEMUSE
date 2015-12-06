#include "value/NullValue.h"
#include "value/Value.h"

namespace dem {
    namespace compiler {
        Value *Value::operator()(Scope &scope) {
            return new NullValue();
        }
    }
}

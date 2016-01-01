#include "value/NullValue.h"

namespace dem {
    namespace compiler {
        Value *Value::operator()() {
            return new NullValue();
        }
    }
}

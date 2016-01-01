#include "value/function/FunctionValue.h"

namespace dem {
    namespace compiler {
        FunctionValue::FunctionValue() :
            FunctionValue(nullptr) {

        }

        FunctionValue::FunctionValue(ObjectValue *parent) :
            ObjectValue(parent) {

        }
    }
}

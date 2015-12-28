#include "GlobalScope.h"
#include "value/function/PrintFunction.h"
#include "value/NumberValue.h"

namespace dem {
    namespace compiler {
        GlobalScope::GlobalScope() : Scope(nullptr) {
            declareVariable(new parser::Identifier("tempo"), new NumberValue(120));
            declareVariable(new parser::Identifier("print"), new PrintFunction());
            declareVariable(new parser::Identifier("Object"), new ObjectValue());
        }
    }
}
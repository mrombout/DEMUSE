#ifndef DEMUSE_PRINTFUNCTION_H
#define DEMUSE_PRINTFUNCTION_H

#include "value/function/InternalFunction.h"

namespace dem {
    namespace compiler {
        class PrintFunction : public InternalFunction {
        public:
            virtual Value *operator()();
        };
    }
}

#endif //DEMUSE_PRINTFUNCTION_H

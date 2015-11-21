#ifndef DEMUSE_NULLVALUE_H
#define DEMUSE_NULLVALUE_H

#include "Value.h"

namespace dem {
    namespace compiler {
        class NullValue : public Value {
        public:
            virtual std::string toString();
        };
    }
}

#endif //DEMUSE_NULLVALUE_H

#ifndef DEMUSE_GLOBALSCOPE_H
#define DEMUSE_GLOBALSCOPE_H

#include "Scope.h"

namespace dem {
    namespace compiler {
        class GlobalScope : public Scope {
        public:
            GlobalScope();
        };
    }
}

#endif //DEMUSE_GLOBALSCOPE_H

#ifndef DEMUSE_COMPILER_H
#define DEMUSE_COMPILER_H

#include "symbol/Program.h"

namespace dem {
    namespace compiler {
        class Compiler {
        public:
            virtual void compile(parser::Program *program) = 0;
        };
    }
}

#endif //DEMUSE_COMPILER_H

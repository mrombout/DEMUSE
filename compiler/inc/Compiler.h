#ifndef DEMUSE_COMPILER_H
#define DEMUSE_COMPILER_H

#include <deque>
#include "symbol/Program.h"
#include "Visitor.h"
#include "value/Value.h"
#include "Scope.h"

namespace dem {
    namespace compiler {
        class Compiler : public parser::Visitor {
        public:
            virtual void compile(parser::Program *program, std::string fileName) = 0;

            virtual Value *returnValue() = 0;
            virtual std::deque<Scope*> &scopes() = 0;
        };
    }
}

#endif //DEMUSE_COMPILER_H

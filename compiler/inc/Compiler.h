#ifndef DEMUSE_COMPILER_H
#define DEMUSE_COMPILER_H

#include <deque>
#include "symbol/Program.h"
#include "Visitor.h"
#include "value/Value.h"
#include "value/ObjectValue.h"

namespace dem {
    namespace compiler {
        /**
         * \brief Compiles a DEMUSE script to another format
         */
        class Compiler : public parser::Visitor {
        public:
            virtual void compile(parser::Program *program, std::string fileName) = 0;

        private:
            virtual Value *returnValue() = 0;
            virtual std::deque<ObjectValue*> &scopes() = 0;
        };
    }
}

#endif //DEMUSE_COMPILER_H

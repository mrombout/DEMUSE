#ifndef DEMUSE_MIDICOMPILER_H
#define DEMUSE_MIDICOMPILER_H

#include <deque>
#include "Compiler.h"
#include "Visitor.h"
#include "Scope.h"

namespace dem {
    namespace compiler {
        class MidiCompiler : public Compiler, parser::Visitor {
        public:
            virtual void compile(parser::Program *program);

            virtual bool visitEnter(parser::Program &program) override;
            virtual bool visitEnter(parser::Block &block) override;
            virtual bool visitEnter(parser::VariableDeclaration &variableDefinition) override;

        private:
            std::deque<Scope*> mScopes;
        };
    }
}

#endif //DEMUSE_MIDICOMPILER_H

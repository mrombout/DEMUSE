#ifndef DEMUSE_MIDICOMPILER_H
#define DEMUSE_MIDICOMPILER_H

#include <deque>
#include "Compiler.h"
#include "Visitor.h"
#include "Scope.h"
#include "ExpressionEvaluator.h"

namespace dem {
    namespace compiler {
        class MidiCompiler : public Compiler {
        public:
            MidiCompiler();

            virtual void compile(parser::Program *program);

            virtual bool visitEnter(parser::Program &program) override;
            virtual bool visitLeave(parser::Program &program) override;

            virtual bool visitEnter(parser::Block &block) override;

            virtual bool visitEnter(parser::FunctionDefinition &functionDefinition) override;
            virtual bool visitEnter(parser::VariableDeclaration &variableDefinition) override;

            virtual bool visitEnter(parser::AssignmentExpression &assignmentExpression) override;

            virtual bool visitEnter(parser::If &ifSymbol) override;

        private:
            ExpressionEvaluator mEvaluator;
            std::deque<Scope*> mScopes;
        };
    }
}

#endif //DEMUSE_MIDICOMPILER_H

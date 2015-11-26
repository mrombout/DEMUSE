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

            virtual bool visitEnter(parser::While &whileSymbol) override;

            virtual Value *returnValue() override;

        private:
            ExpressionEvaluator mEvaluator;
            std::deque<Scope*> mScopes;
            Value *mReturnValue;

        public:
            virtual bool visitEnter(parser::Return &returnSymbol) override;

            virtual bool visitLeave(parser::Block &block) override;

            virtual bool visit(parser::FunctionCall &functionCall) override;

            virtual bool visitEnter(parser::For &forSymbol) override;
        };
    }
}

#endif //DEMUSE_MIDICOMPILER_H

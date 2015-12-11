#ifndef DEMUSE_MIDICOMPILER_H
#define DEMUSE_MIDICOMPILER_H

#include <deque>
#include "Compiler.h"
#include "Visitor.h"
#include "Scope.h"
#include "ExpressionEvaluator.h"
#include "PlayEvaluator.h"

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

            virtual bool visitEnter(parser::Return &returnSymbol) override;

            virtual bool visitLeave(parser::Block &block) override;

            virtual bool visitEnter(parser::PropertyAccessExpression &propertyAccessExpression) override;

            virtual bool visitEnter(parser::For &forSymbol) override;

            virtual bool visitEnter(parser::Play &play) override;
            virtual bool visitLeave(parser::Play &play) override;

            virtual bool visitEnter(parser::Track &track) override;
            virtual bool visitLeave(parser::Track &track) override;

            virtual std::deque<Scope*> &scopes();

        private:
            ExpressionEvaluator mEvaluator;
            PlayEvaluator mPlayEvaluator;
            std::deque<Scope*> mScopes;
            Value *mReturnValue;
        public:
            virtual bool visitEnter(parser::Expression &expression) override;

            virtual bool visit(parser::Expression &expression) override;

            virtual bool visitLeave(parser::Expression &expression) override;
        };
    }
}

#endif //DEMUSE_MIDICOMPILER_H

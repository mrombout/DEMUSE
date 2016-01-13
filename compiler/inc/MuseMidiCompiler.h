#ifndef DEMUSE_MIDICOMPILER_H
#define DEMUSE_MIDICOMPILER_H

#include <deque>
#include "value/ObjectValue.h"
#include "Compiler.h"
#include "Visitor.h"
#include "ExpressionEvaluator.h"
#include "MuseMidiPlayEvaluator.h"

namespace dem {
    namespace compiler {
        /**
         * \brief Compiles a DEMUSE script to a MIDI file
         */
        class MuseMidiCompiler : public Compiler {
        public:
            MuseMidiCompiler();

            virtual void compile(parser::Program *program, std::string fileName);

            virtual bool visitEnter(parser::Program &program) override;
            virtual bool visitLeave(parser::Program &program) override;

            virtual bool visitEnter(parser::Block &block) override;
            virtual bool visitLeave(parser::Block &block) override;

            virtual bool visitEnter(parser::ScopedBlock &block) override;
            virtual bool visitLeave(parser::ScopedBlock &block) override;

            virtual bool visitEnter(parser::FunctionDefinition &functionDefinition) override;
            virtual bool visitLeave(parser::FunctionDefinition &functionDefinition) override;

            virtual bool visitEnter(parser::VariableDeclaration &variableDefinition) override;

            virtual bool visitEnter(parser::AssignmentExpression &assignmentExpression) override;

            virtual bool visitEnter(parser::ExpressionStatement &statement) override;
            virtual bool visitLeave(parser::ExpressionStatement &statement) override;

            virtual bool visitEnter(parser::If &ifSymbol) override;
            virtual bool visitLeave(parser::If &ifSymbol) override;

            virtual bool visitEnter(parser::While &whileSymbol) override;
            virtual bool visitLeave(parser::While &whileSymbol) override;

            virtual bool visitEnter(parser::For &forSymbol) override;
            virtual bool visitLeave(parser::For &forSymbol) override;

            virtual bool visitEnter(parser::Return &returnSymbol) override;
            virtual bool visitLeave(parser::Return &returnSymbol) override;

            virtual bool visitEnter(parser::PropertyAccessExpression &propertyAccessExpression) override;

            virtual bool visitEnter(parser::Play &play) override;
            virtual bool visitLeave(parser::Play &play) override;

            virtual bool visitEnter(parser::Track &track) override;
            virtual bool visitLeave(parser::Track &track) override;

            virtual bool visit(parser::Break &breakSymbol) override;

            virtual bool visit(parser::Continue &continueSymbol) override;

            void doBreak();
            void doNotBreak();
            virtual Value *returnValue() override;
            virtual std::deque<ObjectValue*> &scopes();

        private:
            std::string mFileName;

            ExpressionEvaluator mEvaluator;
            MuseMidiPlayEvaluator mPlayEvaluator;

            std::deque<ObjectValue*> mObjectScopes;

            std::stack<Value*> mReturnValues;

            bool mBreak;
            bool mContinue;
        };
    }
}

#endif //DEMUSE_MIDICOMPILER_H

#include <iostream>
#include "exception/RuntimeException.h"
#include "MuseMidiCompiler.h"
#include "symbol/VariableDeclaration.h"
#include "GlobalScope.h"
#include "value/NullValue.h"
#include "value/function/FunctionValue.h"
#include "value/function/UserFunction.h"

namespace dem {
    namespace compiler {
        MidiCompiler::MidiCompiler() :
                mEvaluator(*this),
                mPlayEvaluator(mEvaluator),
                mReturnValue(nullptr) {

        }

        void MidiCompiler::compile(parser::Program *program, std::string fileName) {
            mFileName = fileName;
            program->accept(*this);
        }

        bool MidiCompiler::visitEnter(parser::Program &program) {
            std::clog << "ENTER - Program" << std::endl;
            
            mScopes.push_front(new GlobalScope());

            return true;
        }

        bool MidiCompiler::visitLeave(parser::Program &program) {
            std::clog << "LEAVE - Program" << std::endl;

            mPlayEvaluator.write(mFileName);

            return true;
        }

        bool MidiCompiler::visitEnter(parser::Track &track) {
            std::clog << "ENTER - Track" << std::endl;

            return true;
        }

        bool MidiCompiler::visitLeave(parser::Track &track) {
            std::clog << "LEAVE - Track" << std::endl;

            return true;
        }

        bool MidiCompiler::visitEnter(parser::Block &block) {
            std::clog << "ENTER - Block" << std::endl;

            mScopes.push_front(new Scope(mScopes.front()));

            return true;
        }

        bool MidiCompiler::visitLeave(parser::Block &block) {
            std::clog << "LEAVE - Block" << std::endl;

            mScopes.pop_front();

            return true;
        }

        bool MidiCompiler::visitEnter(parser::VariableDeclaration &variableDefinition) {
            std::clog << "ENTER - Variable Declaration" << std::endl;

            // TODO: Make proper lvalue class and move this logic?
            parser::Expression &left = variableDefinition.assignment().left();
            if(dynamic_cast<parser::Identifier*>(&left)) {
                parser::Identifier &identifier = static_cast<parser::Identifier&>(left);
                mScopes.front()->declareVariable(&identifier);
            } else if(dynamic_cast<parser::ArrayAccessExpression*>(&left)) {
                // TODO: Array assignment
                throw RuntimeException(variableDefinition, "Array index assignment not implemented yet.");
            }

            return true;
        }


        bool MidiCompiler::visitEnter(parser::FunctionDefinition &functionDefinition) {
            std::clog << "ENTER - Function Definition" << std::endl;

            mScopes.front()->declareVariable(functionDefinition.identifier(), new UserFunction(*this, functionDefinition.parameterList(), functionDefinition.block()));

            return true;
        }

        bool MidiCompiler::visitEnter(parser::AssignmentExpression &assignmentExpression) {
            std::clog << "ENTER - AssignmentExpression" << std::endl;

            mEvaluator.evaluate(mScopes.front(), assignmentExpression);

            return false;
        }

        bool MidiCompiler::visitEnter(parser::If &ifSymbol) {
            std::clog << "ENTER - If" << std::endl;

            parser::Expression &expression = ifSymbol.expression();
            parser::Block &block = ifSymbol.block();
            parser::Block *elseBlock = ifSymbol.elseBlock();

            Value *result = mEvaluator.evaluate(mScopes.front(), expression);
            if(result->asBool()) {
                block.accept(*this);
            } else if(elseBlock) {
                elseBlock->accept(*this);
            }

            return false;
        }

        bool MidiCompiler::visitEnter(parser::While &whileSymbol) {
            std::clog << "ENTER - While" << std::endl;

            parser::Expression &expression = whileSymbol.expression();
            parser::Block &block = whileSymbol.block();

            Value *result = nullptr;
            do {
                result = mEvaluator.evaluate(mScopes.front(), expression);
                if(result->asBool())
                    block.accept(*this);
            } while(result->asBool());

            return false;
        }

        bool MidiCompiler::visitEnter(parser::For &forSymbol) {
            std::clog << "ENTER - For" << std::endl;

            forSymbol.initialization()->accept(*this);
            parser::Expression *condition = forSymbol.condition();
            parser::AssignmentExpression *afterThought = forSymbol.afterThought();
            parser::Block &block = forSymbol.block();
            Value *result = nullptr;
            do {
                result = mEvaluator.evaluate(mScopes.front(), *condition);
                if(result->asBool()) {
                    block.accept(*this);
                    afterThought->accept(*this);
                }
            } while(result->asBool());

            return false;
        }

        bool MidiCompiler::visitEnter(parser::PropertyAccessExpression &propertyAccessExpression) {
            std::clog << "ENTER - PropertyAccessExpression" << std::endl;

            mEvaluator.evaluate(mScopes.front(), propertyAccessExpression);

            return false;
        }

        bool MidiCompiler::visitEnter(parser::Play &play) {
            std::clog << "ENTER - Play" << std::endl;

            mPlayEvaluator.play(play, mScopes.front());

            return false;
        }

        bool MidiCompiler::visitLeave(parser::Play &play) {
            std::clog << "LEAVE - Play" << std::endl;

            return true;
        }

        bool MidiCompiler::visitEnter(parser::Return &returnSymbol) {
            std::clog << "ENTER - Return" << std::endl;

            mReturnValue = mEvaluator.evaluate(mScopes.front(), *returnSymbol.expression());

            return false;
        }

        Value *MidiCompiler::returnValue() {
            if(!mReturnValue)
                return new NullValue();
            return mReturnValue;
        }

        std::deque<Scope*> &MidiCompiler::scopes() {
            return mScopes;
        }

        bool MidiCompiler::visitEnter(parser::FunctionCallExpression &functionCallExpression) {
            std::clog << "ENTER - FunctionCallExpression" << std::endl;

            mEvaluator.evaluate(mScopes.front(), functionCallExpression);

            return true;
        }

        bool MidiCompiler::visitLeave(parser::FunctionCallExpression &functionCallExpression) {
            std::clog << "LEAVE - FunctionCallExpression" << std::endl;

            return true;
        }

        bool MidiCompiler::visitEnter(parser::ExpressionStatement &statement) {
            std::clog << "ENTER - ExpressionStatement" << std::endl;

            mEvaluator.evaluate(mScopes.front(), statement.expression());

            return false;
        }
    }
}

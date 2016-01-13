#include <iostream>
#include <value/BooleanValue.h>
#include "exception/RuntimeException.h"
#include "MuseMidiCompiler.h"
#include "value/NullValue.h"
#include "value/SongValue.h"
#include "value/function/FunctionValue.h"
#include "value/function/UserFunction.h"

namespace dem {
    namespace compiler {
        MuseMidiCompiler::MuseMidiCompiler() :
                mBreak(false),
                mContinue(false),
                mEvaluator(*this),
                mPlayEvaluator(mEvaluator) {

        }

        void MuseMidiCompiler::compile(parser::Program *program, std::string fileName) {
            mFileName = fileName;
            program->accept(*this);
        }

        bool MuseMidiCompiler::visitEnter(parser::Program &program) {
            std::clog << "ENTER - Program" << std::endl;
            
            mObjectScopes.push_front(new SongValue());

            return true;
        }

        bool MuseMidiCompiler::visitLeave(parser::Program &program) {
            std::clog << "LEAVE - Program" << std::endl;

            mPlayEvaluator.write(mFileName);

            return true;
        }

        bool MuseMidiCompiler::visitEnter(parser::Track &track) {
            std::clog << "ENTER - Track" << std::endl;

            mPlayEvaluator.setTrack(track);

            return true;
        }

        bool MuseMidiCompiler::visitLeave(parser::Track &track) {
            std::clog << "LEAVE - Track" << std::endl;

            return true;
        }

        bool MuseMidiCompiler::visitEnter(parser::Block &block) {
            std::clog << "ENTER - Block" << std::endl;

            return true;
        }

        bool MuseMidiCompiler::visitLeave(parser::Block &block) {
            std::clog << "LEAVE - Block" << std::endl;

            return true;
        }

        bool MuseMidiCompiler::visitEnter(parser::ScopedBlock &block) {
            std::clog << "ENTER - ScopedBlock" << std::endl;

            return true;
        }

        bool MuseMidiCompiler::visitLeave(parser::ScopedBlock &block) {
            std::clog << "LEAVE - ScopedBlock" << std::endl;

            mBreak = false;

            return true;
        }

        bool MuseMidiCompiler::visitEnter(parser::VariableDeclaration &variableDefinition) {
            std::clog << "ENTER - Variable Declaration" << std::endl;

            // TODO: Make proper lvalue class and move this logic?
            parser::Expression &left = variableDefinition.assignment().left();
            if(dynamic_cast<parser::Identifier*>(&left)) {
                parser::Identifier &identifier = static_cast<parser::Identifier&>(left);
                mObjectScopes.front()->declareVariable(&identifier);
            } else if(dynamic_cast<parser::ArrayAccessExpression*>(&left)) {
                // TODO: Array assignment
                throw RuntimeException("Array index assignment not implemented yet.");
            }

            return true;
        }


        bool MuseMidiCompiler::visitEnter(parser::FunctionDefinition &functionDefinition) {
            std::clog << "ENTER - Function Definition" << std::endl;

            mObjectScopes.front()->declareVariable(functionDefinition.identifier(), new UserFunction(*this, mObjectScopes.front(), functionDefinition.parameterList(), functionDefinition.block()));

            return false;
        }

        bool MuseMidiCompiler::visitLeave(parser::FunctionDefinition &functionDefinition) {
            std::clog << "LEAVE - Function Definition" << std::endl;

            mBreak = false;

            return true;
        }

        bool MuseMidiCompiler::visitEnter(parser::AssignmentExpression &assignmentExpression) {
            std::clog << "ENTER - AssignmentExpression" << std::endl;

            //mBreak = false;
            mEvaluator.evaluate(mObjectScopes.front(), assignmentExpression);

            return false;
        }

        bool MuseMidiCompiler::visitEnter(parser::If &ifSymbol) {
            std::clog << "ENTER - If" << std::endl;

            parser::Expression &expression = ifSymbol.expression();
            parser::Block &block = ifSymbol.block();
            parser::Block *elseBlock = ifSymbol.elseBlock();

            Value *result = mEvaluator.evaluate(mObjectScopes.front(), expression);
            if(result->asBool()) {
                block.accept(*this);
            } else if(elseBlock) {
                elseBlock->accept(*this);
            }

            return false;
        }

        bool MuseMidiCompiler::visitLeave(parser::If &ifSymbol) {
            std::clog << "LEAVE - If" << std::endl;

            return !mBreak;
        }

        bool MuseMidiCompiler::visitEnter(parser::While &whileSymbol) {
            std::clog << "ENTER - While" << std::endl;

            parser::Expression &expression = whileSymbol.expression();
            parser::Block &block = whileSymbol.block();

            Value *result = nullptr;
            do {
                if(mBreak) {
                    mBreak = false;
                    break;
                }
                if(mContinue) {
                    mContinue = false;
                    continue;
                }
                result = mEvaluator.evaluate(mObjectScopes.front(), expression);
                if(result->asBool())
                    block.accept(*this);
            } while(result->asBool());

            return false;
        }

        bool MuseMidiCompiler::visitLeave(parser::While &whileSymbol) {
            std::clog << "LEAVE - While" << std::endl;

            return !mBreak;
        }

        bool MuseMidiCompiler::visitEnter(parser::For &forSymbol) {
            std::clog << "ENTER - For" << std::endl;

            if(forSymbol.initialization())
                forSymbol.initialization()->accept(*this);

            parser::Expression *condition = forSymbol.condition();
            if(!condition)
                condition = new parser::BoolLiteral(forSymbol.token(), true);

            parser::AssignmentExpression *afterThought = forSymbol.afterThought();
            parser::Block &block = forSymbol.block();
            Value *result = nullptr;
            do {
                result = mEvaluator.evaluate(mObjectScopes.front(), *condition);
                if(result->asBool()) {
                    block.accept(*this);
                    if(mBreak) {
                        mBreak = false;
                        break;
                    }
                    if(afterThought)
                        afterThought->accept(*this);
                }
            } while(result->asBool());

            return false;
        }

        bool MuseMidiCompiler::visitLeave(parser::For &forSymbol) {
            std::clog << "LEAVE - For" << std::endl;

            return !mBreak;
        }

        bool MuseMidiCompiler::visitEnter(parser::PropertyAccessExpression &propertyAccessExpression) {
            std::clog << "ENTER - PropertyAccessExpression" << std::endl;

            mEvaluator.evaluate(mObjectScopes.front(), propertyAccessExpression);

            return false;
        }

        bool MuseMidiCompiler::visitEnter(parser::Play &play) {
            std::clog << "ENTER - Play" << std::endl;

            mPlayEvaluator.play(play, mObjectScopes.front());

            return false;
        }

        bool MuseMidiCompiler::visitLeave(parser::Play &play) {
            std::clog << "LEAVE - Play" << std::endl;

            return true;
        }

        bool MuseMidiCompiler::visitEnter(parser::Return &returnSymbol) {
            std::clog << "ENTER - Return" << std::endl;

            mReturnValues.push(mEvaluator.evaluate(mObjectScopes.front(), returnSymbol.expression()));
            mBreak = true;

            return false;
        }

        bool MuseMidiCompiler::visitLeave(parser::Return &returnSymbol) {
            std::clog << "LEAVE - Return" << std::endl;

            return false;
        }

        Value *MuseMidiCompiler::returnValue() {
            if(mReturnValues.empty())
                return new NullValue();
            return mReturnValues.top();
        }

        std::deque<ObjectValue*> &MuseMidiCompiler::scopes() {
            return mObjectScopes;
        }

        bool MuseMidiCompiler::visitEnter(parser::ExpressionStatement &statement) {
            std::clog << "ENTER - ExpressionStatement" << std::endl;

            mEvaluator.evaluate(mObjectScopes.front(), statement.expression());

            return false;
        }

        bool MuseMidiCompiler::visitLeave(parser::ExpressionStatement &statement) {
            std::clog << "LEAVE - ExpressionStatement" << std::endl;

            return true;
        }

        bool MuseMidiCompiler::visit(parser::Break &breakSymbol) {
            std::clog << "ENTER - Break" << std::endl;

            mBreak = true;

            return false;
        }

        bool MuseMidiCompiler::visit(parser::Continue &continueSymbol) {
            std::clog << "ENTER - Continue" << std::endl;

            mContinue = true;

            return false;
        }

        void MuseMidiCompiler::doBreak() {
            mBreak = true;
        }

        void MuseMidiCompiler::doNotBreak() {
            mBreak = false;
        }
    }
}

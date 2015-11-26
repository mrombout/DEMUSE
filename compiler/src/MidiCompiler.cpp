#include <iostream>
#include "MidiCompiler.h"
#include "symbol/VariableDeclaration.h"
#include "GlobalScope.h"
#include "function/UserFunction.h"
#include "value/NullValue.h"

namespace dem {
    namespace compiler {
        MidiCompiler::MidiCompiler() :
                mEvaluator(*this) {

        }

        void MidiCompiler::compile(parser::Program *program) {
            program->accept(*this);
        }

        bool MidiCompiler::visitEnter(parser::Program &program) {
            std::cout << "ENTER - Program" << std::endl;
            
            mScopes.push_front(new GlobalScope());

            return true;
        }

        bool MidiCompiler::visitLeave(parser::Program &program) {
            std::cout << "LEAVE - Program" << std::endl;

            return true;
        }

        bool MidiCompiler::visitEnter(parser::Block &block) {
            std::cout << "ENTER - Block" << std::endl;

            mScopes.push_front(new Scope(mScopes.front()));

            return true;
        }

        bool MidiCompiler::visitLeave(parser::Block &block) {
            std::cout << "LEAVE - Block" << std::endl;

            mScopes.pop_front();

            return true;
        }

        bool MidiCompiler::visitEnter(parser::VariableDeclaration &variableDefinition) {
            std::cout << "ENTER - Variable Declaration" << std::endl;

            mScopes.front()->declareVariable(&variableDefinition.assignment().left());

            return true;
        }


        bool MidiCompiler::visitEnter(parser::FunctionDefinition &functionDefinition) {
            std::cout << "ENTER - Function Definition" << std::endl;

            mScopes.front()->declareFunction(new UserFunction(*this, functionDefinition));

            return true;
        }

        bool MidiCompiler::visitEnter(parser::AssignmentExpression &assignmentExpression) {
            std::cout << "ENTER - AssignmentExpression" << std::endl;

            mEvaluator.evaluate(mScopes.front(), assignmentExpression);

            return true;
        }

        bool MidiCompiler::visitEnter(parser::If &ifSymbol) {
            std::cout << "ENTER - If" << std::endl;

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
            std::cout << "ENTER - While" << std::endl;

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
            std::cout << "ENTER - For" << std::endl;

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

        bool MidiCompiler::visit(parser::FunctionCall &functionCall) {
            std::cout << "ENTER - FunctionCall" << std::endl;

            mEvaluator.evaluate(mScopes.front(), functionCall);

            return false;
        }

        bool MidiCompiler::visitEnter(parser::Return &returnSymbol) {
            std::cout << "ENTER - Return" << std::endl;

            mReturnValue = mEvaluator.evaluate(mScopes.front(), *returnSymbol.expression());

            return false;
        }

        Value *MidiCompiler::returnValue() {
            if(!mReturnValue)
                return new NullValue();
            return mReturnValue;
        }
    }
}

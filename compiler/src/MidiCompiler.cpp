#include <iostream>
#include "MidiCompiler.h"
#include "symbol/VariableDeclaration.h"
#include "GlobalScope.h"
#include "function/UserFunction.h"

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
    }
}

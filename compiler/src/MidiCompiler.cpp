#include <iostream>
#include "MidiCompiler.h"
#include "symbol/VariableDeclaration.h"
#include "GlobalScope.h"

namespace dem {
    namespace compiler {
        void MidiCompiler::compile(parser::Program *program) {
            program->accept(*this);
        }

        bool MidiCompiler::visitEnter(parser::Program &program) {
            std::cout << "ENTER - Program" << std::endl;
            
            mScopes.push_front(new GlobalScope());

            return true;
        }

        bool MidiCompiler::visitEnter(parser::Block &block) {
            std::cout << "ENTER - Block" << std::endl;

            mScopes.push_front(new Scope(mScopes.front()));

            return false;
        }

        bool MidiCompiler::visitEnter(parser::VariableDeclaration &variableDefinition) {
            std::cout << "ENTER - Variable Declaration" << std::endl;

            mScopes.front()->declareVariable(&variableDefinition.assignment().left());

            return true;
        }
    }
}

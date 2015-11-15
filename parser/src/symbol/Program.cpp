#include "symbol/Program.h"

namespace dem {
    namespace parser {
        Program::Program(std::vector<Statement*> statements) :
            mStatements(statements) {

        }

        Program::~Program() {

        }

        const std::vector<Statement*> &Program::statements() const {
            return mStatements;
        }
    }
}
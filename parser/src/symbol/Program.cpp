#include "symbol/Program.h"

namespace dem {
    namespace parser {
        Program::Program(std::vector<Statement*> statements) :
            mStatements(statements) {

        }

        const std::vector<Statement*> &Program::statements() const {
            return mStatements;
        }
    }
}
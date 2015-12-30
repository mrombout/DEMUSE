#ifndef DEMUSE_COMPOUNDSTATEMENT_H
#define DEMUSE_COMPOUNDSTATEMENT_H

#include "Statement.h"

namespace dem {
    namespace parser {
        class CompoundStatement : public Statement {
        public:
            CompoundStatement(const lexer::Token &token);
        };
    }
}

#endif //DEMUSE_COMPOUNDSTATEMENT_H

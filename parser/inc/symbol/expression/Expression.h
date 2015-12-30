#ifndef DEMUSE_EXPRESSION_H
#define DEMUSE_EXPRESSION_H

#include <string>
#include "symbol/CompoundStatement.h"

namespace dem {
    namespace parser {
        class Expression : public CompoundStatement {
        public:
            Expression(const lexer::Token &token);
            virtual ~Expression() { }
        };
    }
}

#endif //DEMUSE_EXPRESSION_H

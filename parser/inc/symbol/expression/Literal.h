#ifndef DEMUSE_LITERAL_H
#define DEMUSE_LITERAL_H

#include "Expression.h"

namespace dem {
    namespace parser {
        class Literal : public Expression {
        public:
            Literal(const lexer::Token &token);
        };
    }
}

#endif //DEMUSE_LITERAL_H

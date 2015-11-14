#ifndef DEMUSE_EXPRESSIONFACTORY_H
#define DEMUSE_EXPRESSIONFACTORY_H

#include <deque>
#include "symbol/Expression.h"
#include "Token.h"

namespace dem {
    namespace parser {
        class ExpressionFactory {
        public:
            static Expression *produce(std::deque<lexer::Token> &tokens);
        };
    }
}

#endif //DEMUSE_EXPRESSIONFACTORY_H

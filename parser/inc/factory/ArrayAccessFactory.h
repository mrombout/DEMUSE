#ifndef DEMUSE_ARRAYACCESSFACTORY_H
#define DEMUSE_ARRAYACCESSFACTORY_H

#include <deque>
#include "SymbolFactory.h"
#include "symbol/expression/ArrayAccessExpression.h"

namespace dem {
    namespace parser {
        class ArrayAccessFactory : public SymbolFactory {
        public:
            static ArrayAccessExpression *produce(std::deque<lexer::Token> &tokens, Expression *lvalue);
        };
    }
}

#endif //DEMUSE_ARRAYACCESSFACTORY_H

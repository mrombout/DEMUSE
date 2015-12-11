#ifndef DEMUSE_PROCEDURECALLFACTORY_H
#define DEMUSE_PROCEDURECALLFACTORY_H

#include <deque>
#include "factory/SymbolFactory.h"
#include "symbol/expression/FunctionCallExpression.h"

namespace dem {
    namespace parser {
        class FunctionCallExpressionFactory : public SymbolFactory {
        public:
            static FunctionCallExpression *produce(std::deque<lexer::Token> &tokens, Expression *expression);
        };
    }
}

#endif //DEMUSE_PROCEDURECALLFACTORY_H

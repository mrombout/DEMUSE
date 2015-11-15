#ifndef DEMUSE_BREAKFACTORY_H
#define DEMUSE_BREAKFACTORY_H

#include <deque>
#include "SymbolFactory.h"
#include "Token.h"
#include "symbol/Break.h"

namespace dem {
    namespace parser {
        class BreakFactory : public SymbolFactory {
        public:
            static Break *produce(std::deque<lexer::Token> &tokens);
        };
    }
}

#endif //DEMUSE_BREAKFACTORY_H

#ifndef DEMUSE_CONTINUEFACTORY_H
#define DEMUSE_CONTINUEFACTORY_H

#include <deque>
#include "Token.h"
#include "SymbolFactory.h"
#include "symbol/Continue.h"

namespace dem {
    namespace parser {
        class ContinueFactory : public SymbolFactory {
        public:
            static Continue *produce(std::deque<lexer::Token> &tokens);
        };
    }
}

#endif //DEMUSE_CONTINUEFACTORY_H

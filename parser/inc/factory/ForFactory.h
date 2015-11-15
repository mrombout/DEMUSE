#ifndef DEMUSE_FORFACTORY_H
#define DEMUSE_FORFACTORY_H

#include <deque>
#include "SymbolFactory.h"
#include "symbol/For.h"
#include "Token.h"

namespace dem {
    namespace parser {
        class ForFactory : public SymbolFactory {
        public:
            static For *produce(std::deque<lexer::Token> &tokens);
        };
    }
}

#endif //DEMUSE_FORFACTORY_H

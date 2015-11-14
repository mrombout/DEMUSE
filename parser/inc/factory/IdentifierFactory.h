#ifndef DEMUSE_IDENTIFIERFACTORY_H
#define DEMUSE_IDENTIFIERFACTORY_H

#include <deque>
#include "symbol/Identifier.h"
#include "SymbolFactory.h"
#include "Token.h"

namespace dem {
    namespace parser {
        class IdentifierFactory : public SymbolFactory {
        public:
            static Identifier *produce(std::deque<lexer::Token> &tokens);
        };
    }
}

#endif //DEMUSE_IDENTIFIERFACTORY_H

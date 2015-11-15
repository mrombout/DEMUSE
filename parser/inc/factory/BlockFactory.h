#ifndef DEMUSE_BLOCKFACTORY_H
#define DEMUSE_BLOCKFACTORY_H

#include <deque>
#include "SymbolFactory.h"
#include "symbol/Block.h"
#include "Token.h"

namespace dem {
    namespace parser {
        class BlockFactory : public SymbolFactory {
        public:
            static Block *produce(std::deque<lexer::Token> &tokens);
        };
    }
}

#endif //DEMUSE_BLOCKFACTORY_H

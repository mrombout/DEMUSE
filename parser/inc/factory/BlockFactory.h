#ifndef DEMUSE_BLOCKFACTORY_H
#define DEMUSE_BLOCKFACTORY_H

#include <deque>
#include "SymbolFactory.h"
#include "Token.h"

namespace dem {
    namespace parser {
        class Block;
    }
}

namespace dem {
    namespace parser {
        /**
         * \brief Represents a block.
         *
         * \ebnf block = "{" { statement } "}" ;
         */
        class BlockFactory : public SymbolFactory {
        public:
            static Block *produce(std::deque<lexer::Token> &tokens, ParseResults &results);
        };
    }
}

#endif //DEMUSE_BLOCKFACTORY_H

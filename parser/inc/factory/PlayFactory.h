#ifndef DEMUSE_PLAYFACTORY_H
#define DEMUSE_PLAYFACTORY_H

#include <deque>
#include "SymbolFactory.h"
#include "symbol/play/Play.h"

namespace dem {
    namespace parser {
        class PlayFactory : public SymbolFactory {
        public:
            static Play *produce(std::deque<lexer::Token> &tokens);
        };
    }
}

#endif //DEMUSE_PLAYFACTORY_H
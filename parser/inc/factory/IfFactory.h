#ifndef DEMUSE_IFFACTORY_H
#define DEMUSE_IFFACTORY_H

#include "SymbolFactory.h"
#include "symbol/If.h"

namespace dem {
    namespace parser {
        class IfFactory : public SymbolFactory {
        public:
            static If *produce(std::deque<lexer::Token> &tokens);
        };
    }
}

#endif //DEMUSE_IFFACTORY_H

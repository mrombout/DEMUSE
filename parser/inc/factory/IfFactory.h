#ifndef DEMUSE_IFFACTORY_H
#define DEMUSE_IFFACTORY_H

#include <deque>
#include "Token.h"
#include "SymbolFactory.h"

namespace dem {
    namespace parser {
        class If;
    }
}

namespace dem {
    namespace parser {
        class IfFactory : public SymbolFactory {
        public:
            static If *produce(std::deque<lexer::Token> &tokens, ParseResults &results);
        };
    }
}

#endif //DEMUSE_IFFACTORY_H

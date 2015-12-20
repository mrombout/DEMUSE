#ifndef DEMUSE_PRIMITIVEFACTORY_H
#define DEMUSE_PRIMITIVEFACTORY_H

#include <deque>
#include "Token.h"
#include "SymbolFactory.h"

namespace dem {
    namespace parser {
        class Primitive;
    }
}

namespace dem {
    namespace parser {
        class PrimitiveFactory : public SymbolFactory {
        public:
            static Primitive *produce(std::deque<lexer::Token> &tokens, ParseResults &results);
        };
    }
}

#endif //DEMUSE_PRIMITIVEFACTORY_H

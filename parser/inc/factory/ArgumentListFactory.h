#ifndef DEMUSE_ARGUMENTLISTFACTORY_H
#define DEMUSE_ARGUMENTLISTFACTORY_H

#include <deque>
#include "SymbolFactory.h"
#include "Token.h"

namespace dem {
    namespace parser {
        class ArgumentList;
    }
}

namespace dem {
    namespace parser {
        class ArgumentListFactory : public SymbolFactory {
        public:
            static ArgumentList *produce(std::deque<lexer::Token> &tokens);
        };
    }
}

#endif //DEMUSE_ARGUMENTLISTFACTORY_H

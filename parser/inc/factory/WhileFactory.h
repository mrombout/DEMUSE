#ifndef DEMUSE_WHILEFACTORY_H
#define DEMUSE_WHILEFACTORY_H

#include <deque>
#include "SymbolFactory.h"
#include "symbol/While.h"
#include "Token.h"

namespace dem {
    namespace parser {
        class WhileFactory : public SymbolFactory {
        public:
            static While *produce(std::deque<lexer::Token> &tokens);
        };
    }
}

#endif //DEMUSE_WHILEFACTORY_H

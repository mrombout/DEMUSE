#ifndef DEMUSE_RETURNFACTORY_H
#define DEMUSE_RETURNFACTORY_H

#include <deque>
#include "Token.h"
#include "symbol/Return.h"
#include "factory/SymbolFactory.h"

namespace dem {
    namespace parser {
        class ReturnFactory : public SymbolFactory {
        public:
            static Return *produce(std::deque<lexer::Token> tokens);
        };
    }
}

#endif //DEMUSE_RETURNFACTORY_H

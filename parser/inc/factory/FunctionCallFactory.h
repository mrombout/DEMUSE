#ifndef DEMUSE_PROCEDURECALLFACTORY_H
#define DEMUSE_PROCEDURECALLFACTORY_H

#include <deque>
#include "factory/SymbolFactory.h"
#include "symbol/FunctionCall.h"

namespace dem {
    namespace parser {
        class FunctionCallFactory : public SymbolFactory {
        public:
            static FunctionCall *produce(std::deque<lexer::Token> &tokens);
        };
    }
}

#endif //DEMUSE_PROCEDURECALLFACTORY_H

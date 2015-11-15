#ifndef DEMUSE_PARAMETERLISTFACTORY_H
#define DEMUSE_PARAMETERLISTFACTORY_H

#include <deque>
#include "SymbolFactory.h"
#include "Token.h"
#include "symbol/ParameterList.h"

namespace dem {
    namespace parser {
        class ParameterListFactory : public SymbolFactory {
        public:
            static ParameterList *produce(std::deque<lexer::Token> &tokens);
        };
    }
}

#endif //DEMUSE_PARAMETERLISTFACTORY_H
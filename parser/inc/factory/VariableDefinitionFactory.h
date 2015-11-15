#ifndef DEMUSE_VARIABLEDEFINITIONFACTORY_H
#define DEMUSE_VARIABLEDEFINITIONFACTORY_H

#include <deque>
#include "SymbolFactory.h"
#include "symbol/VariableDefinition.h"
#include "Token.h"

namespace dem {
    namespace parser {
        class VariableDefinitionFactory : public SymbolFactory {
        public:
            static VariableDefinition *produce(std::deque<lexer::Token> &tokens);
        };
    }
}

#endif //DEMUSE_VARIABLEDEFINITIONFACTORY_H

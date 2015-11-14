#ifndef DEMUSE_FUNCTIONDEFINITIONFACTORY_H
#define DEMUSE_FUNCTIONDEFINITIONFACTORY_H

#include <deque>
#include "symbol/FunctionDefinition.h"
#include "Token.h"

namespace dem {
    namespace parser {
        class FunctionDefinitionFactory {
        public:
            static FunctionDefinition *produce(std::deque<lexer::Token> &tokens);
        };
    }
}

#endif //DEMUSE_FUNCTIONDEFINITIONFACTORY_H

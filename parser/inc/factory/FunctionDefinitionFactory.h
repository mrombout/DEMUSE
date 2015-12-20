#ifndef DEMUSE_FUNCTIONDEFINITIONFACTORY_H
#define DEMUSE_FUNCTIONDEFINITIONFACTORY_H

#include <deque>
#include "SymbolFactory.h"
#include "Token.h"

namespace dem {
    namespace parser {
        class FunctionDefinition;
    }
}

namespace dem {
    namespace parser {
        class FunctionDefinitionFactory : public SymbolFactory {
        public:
            static FunctionDefinition *produce(std::deque<lexer::Token> &tokens, ParseResults &results);
        };
    }
}

#endif //DEMUSE_FUNCTIONDEFINITIONFACTORY_H

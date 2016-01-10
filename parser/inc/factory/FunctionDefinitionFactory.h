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
        /**
         * \brief Produces a function definition.
         *
         * \ebnf function_def = "function" identifier "(" [ parameter_list ] ")" block ;
         */
        class FunctionDefinitionFactory : public SymbolFactory {
        public:
            static FunctionDefinition *produce(std::deque<lexer::Token> &tokens, ParseResults &results);
        };
    }
}

#endif //DEMUSE_FUNCTIONDEFINITIONFACTORY_H

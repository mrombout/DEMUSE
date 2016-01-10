#ifndef DEMUSE_PARAMETERLISTFACTORY_H
#define DEMUSE_PARAMETERLISTFACTORY_H

#include <deque>
#include "SymbolFactory.h"
#include "Token.h"

namespace dem {
    namespace parser {
        class ParameterList;
    }
}

namespace dem {
    namespace parser {
        /**
         * \brief Produces a parameter list of a function or object definition
         *
         * \ebnf parameter_list = identifier | parameter_list "," identifier ;
         */
        class ParameterListFactory : public SymbolFactory {
        public:
            static ParameterList *produce(std::deque<lexer::Token> &tokens, ParseResults &results);
        };
    }
}

#endif //DEMUSE_PARAMETERLISTFACTORY_H

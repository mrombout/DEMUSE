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
        /**
         * \brief Produces an argument list of a function call.
         *
         * \ebnf argument_list = expression | argument_list "," expression ;
         */
        class ArgumentListFactory : public SymbolFactory {
        public:
            static ArgumentList *produce(std::deque<lexer::Token> &tokens, ParseResults &results);
        };
    }
}

#endif //DEMUSE_ARGUMENTLISTFACTORY_H

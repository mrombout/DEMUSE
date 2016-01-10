#ifndef DEMUSE_NEWOBJECTFACTORY_H
#define DEMUSE_NEWOBJECTFACTORY_H

#include <deque>
#include "symbol/NewInstance.h"
#include "SymbolFactory.h"

namespace dem {
    namespace parser {
        /**
         * \brief Produces a new instance statement
         *
         * \ebnf new_instance = "new" identfier "(" argument_list ")" ;
         */
        class NewInstanceFactory : public SymbolFactory {
        public:
            static NewInstance *produce(std::deque<lexer::Token> &tokens, ParseResults &results);
        };
    }
}

#endif //DEMUSE_NEWOBJECTFACTORY_H

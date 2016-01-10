#ifndef DEMUSE_RETURNFACTORY_H
#define DEMUSE_RETURNFACTORY_H

#include <deque>
#include "Token.h"
#include "SymbolFactory.h"

namespace dem {
    namespace parser {
        class Return;
    }
}

namespace dem {
    namespace parser {
        /**
         * \brief Produces a return statement
         *
         * \ebnf return_stmt = "return" expression ;
         */
        class ReturnFactory : public SymbolFactory {
        public:
            static Return *produce(std::deque<lexer::Token> &tokens, ParseResults &results);
        };
    }
}

#endif //DEMUSE_RETURNFACTORY_H

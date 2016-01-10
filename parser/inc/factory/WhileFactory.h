#ifndef DEMUSE_WHILEFACTORY_H
#define DEMUSE_WHILEFACTORY_H

#include <deque>
#include "SymbolFactory.h"
#include "Token.h"

namespace dem {
    namespace parser {
        class While;
    }
}

namespace dem {
    namespace parser {
        /**
         * \brief Produces a while statement.
         *
         * \ebnf while_stmt = "while(" conditional ")" block ;
         */
        class WhileFactory : public SymbolFactory {
        public:
            static While *produce(std::deque<lexer::Token> &tokens, ParseResults &results);
        };
    }
}

#endif //DEMUSE_WHILEFACTORY_H

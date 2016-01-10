#ifndef DEMUSE_IFFACTORY_H
#define DEMUSE_IFFACTORY_H

#include <deque>
#include "Token.h"
#include "SymbolFactory.h"

namespace dem {
    namespace parser {
        class If;
    }
}

namespace dem {
    namespace parser {
        /**
         * \brief Produces an if statement
         *
         * Produces an "if" statement, this also includes the optional "else" according to the EBNF. As defined in the
         * EBNF, an if statement may take a block or a single statement. This also allows the user to use "if/else if"
         * constructs since an "if" is considered a single statement.
         *
         * \ebnf if_stmt = "if(" conditional ")" block [ "else" ( block | statement ) ] ;
         */
        class IfFactory : public SymbolFactory {
        public:
            static If *produce(std::deque<lexer::Token> &tokens, ParseResults &results);
        };
    }
}

#endif //DEMUSE_IFFACTORY_H

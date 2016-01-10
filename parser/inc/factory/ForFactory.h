#ifndef DEMUSE_FORFACTORY_H
#define DEMUSE_FORFACTORY_H

#include <deque>
#include "SymbolFactory.h"
#include "Token.h"

namespace dem {
    namespace parser {
        class For;
    }
}

namespace dem {
    namespace parser {
        /**
         * \brief Produces a for statement.
         *
         * \ebnf for_stmt = "for(" ( terminator | variable_def_stmt | assignment_stmt ) ( terminator | conditional ) ( terminator | assignment_stmt ) ")" block ;
         */
        class ForFactory : public SymbolFactory {
        public:
            static For *produce(std::deque<lexer::Token> &tokens, ParseResults &results);
        };
    }
}

#endif //DEMUSE_FORFACTORY_H

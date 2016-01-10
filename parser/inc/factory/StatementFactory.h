#ifndef DEMUSE_STATEMENTFACTORY_H
#define DEMUSE_STATEMENTFACTORY_H

#include <deque>
#include "SymbolFactory.h"
#include "symbol/Statement.h"
#include "Token.h"

namespace dem {
    namespace parser {
        class Statement;
    }
}

namespace dem {
    namespace parser {
        /**
         * \brief Produces a statement
         *
         * \ebnf statement = ( simple_statement | compound_statement ) ;
         */
        class StatementFactory : public SymbolFactory {
        public:
            static Statement *produce(std::deque<lexer::Token> &tokens, ParseResults &results);
        };
    }
}

#endif //DEMUSE_STATEMENTFACTORY_H

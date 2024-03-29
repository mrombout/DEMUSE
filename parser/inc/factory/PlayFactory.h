#ifndef DEMUSE_PLAYFACTORY_H
#define DEMUSE_PLAYFACTORY_H

#include <deque>
#include "SymbolFactory.h"
#include "symbol/play/Play.h"

namespace dem {
    namespace parser {
        /**
         * \brief Produces a play statement
         *
         * \ebnf play_stmt = "<<" { note | identifier } ">>" ;
         */
        class PlayFactory : public SymbolFactory {
        public:
            static Play *produce(std::deque<lexer::Token> &tokens, ParseResults &results);
            static Expression *parsePart(std::deque<lexer::Token> &tokens, ParseResults &results);
        };
    }
}

#endif //DEMUSE_PLAYFACTORY_H

#ifndef DEMUSE_BREAKFACTORY_H
#define DEMUSE_BREAKFACTORY_H

#include <deque>
#include "SymbolFactory.h"
#include "Token.h"

namespace dem {
    namespace parser {
        class Break;
    }
}

namespace dem {
    namespace parser {
        /**
         * \brief Represents a break statement.
         *
         * \ebnf break_stmt = "break" ;
         */
        class BreakFactory : public SymbolFactory {
        public:
            static Break *produce(std::deque<lexer::Token> &tokens, ParseResults &results);
        };
    }
}

#endif //DEMUSE_BREAKFACTORY_H

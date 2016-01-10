#ifndef DEMUSE_INSTRUMENTFACTORY_H
#define DEMUSE_INSTRUMENTFACTORY_H

#include "SymbolFactory.h"
#include "symbol/play/Instrument.h"

namespace dem {
    namespace parser {
        /**
         * \brief Produces an instrument change.
         *
         * \ebnf instrument = "I[" ( number | identifier ) "]"
         */
        class InstrumentFactory : public SymbolFactory {
        public:
            static Instrument *produce(std::deque<lexer::Token> &tokens, ParseResults &results);
        };
    }
}

#endif //DEMUSE_INSTRUMENTFACTORY_H

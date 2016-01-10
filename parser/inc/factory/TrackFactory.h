#ifndef DEMUSE_TRACKFACTORY_H
#define DEMUSE_TRACKFACTORY_H

#include <deque>
#include <regex>
#include "SymbolFactory.h"
#include "symbol/Track.h"

namespace dem {
    namespace parser {
        /**
         * \brief Produces a track
         *
         * \ebnf track = "track" (1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 ) block ;
         */
        class TrackFactory : public SymbolFactory {
        public:
            static Track *produce(std::deque<lexer::Token> &tokens, ParseResults &results);

        private:
            static std::regex RGX_CHANNEL;
        };
    }
}

#endif //DEMUSE_TRACKFACTORY_H

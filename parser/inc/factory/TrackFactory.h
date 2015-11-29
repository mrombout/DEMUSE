#ifndef DEMUSE_TRACKFACTORY_H
#define DEMUSE_TRACKFACTORY_H

#include <deque>
#include <regex>
#include "SymbolFactory.h"
#include "symbol/Track.h"

namespace dem {
    namespace parser {
        class TrackFactory : public SymbolFactory {
        public:
            static Track *produce(std::deque<lexer::Token> &tokens);

        private:
            static std::regex RGX_CHANNEL;
        };
    }
}

#endif //DEMUSE_TRACKFACTORY_H

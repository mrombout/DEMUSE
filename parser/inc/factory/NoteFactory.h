#ifndef DEMUSE_NOTEFACTORY_H
#define DEMUSE_NOTEFACTORY_H

#include <regex>
#include <deque>
#include "SymbolFactory.h"
#include "symbol/play/Note.h"

namespace dem {
    namespace parser {
        class NoteFactory : public SymbolFactory {
        public:
            static Note *produce(std::deque<lexer::Token> &tokens);
        };
    }
}

#endif //DEMUSE_NOTEFACTORY_H

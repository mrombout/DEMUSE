#ifndef DEMUSE_PROGRAMFACTORY_H
#define DEMUSE_PROGRAMFACTORY_H

#include <deque>
#include "SymbolFactory.h"
#include "symbol/Program.h"
#include "Token.h"

namespace dem {
    namespace parser {
        class ProgramFactory : public SymbolFactory {
        public:
            static Program *produce(std::deque<lexer::Token> &tokens);
        };
    }
}

#endif //DEMUSE_PROGRAMFACTORY_H

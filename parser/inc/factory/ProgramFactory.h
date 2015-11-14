#ifndef DEMUSE_PROGRAMFACTORY_H
#define DEMUSE_PROGRAMFACTORY_H

#include <deque>
#include "Symbol.h"
#include "Token.h"

namespace dem {
    namespace parser {
        class ProgramFactory {
        public:
            static Symbol produce(std::deque<lexer::Token> &tokens);
        };
    }
}

#endif //DEMUSE_PROGRAMFACTORY_H

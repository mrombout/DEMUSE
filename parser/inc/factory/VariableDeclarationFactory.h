#ifndef DEMUSE_VARIABLEDECLARATIONFACTORY_H
#define DEMUSE_VARIABLEDECLARATIONFACTORY_H

#include <deque>
#include "SymbolFactory.h"
#include "Token.h"

namespace dem {
    namespace parser {
        class VariableDeclaration;
    }
}

namespace dem {
    namespace parser {
        class VariableDeclarationFactory : public SymbolFactory {
        public:
            static VariableDeclaration *produce(std::deque<lexer::Token> &tokens, ParseResults &results);
        };
    }
}

#endif //DEMUSE_VARIABLEDECLARATIONFACTORY_H

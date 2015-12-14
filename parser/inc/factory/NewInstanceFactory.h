#ifndef DEMUSE_NEWOBJECTFACTORY_H
#define DEMUSE_NEWOBJECTFACTORY_H

#include <deque>
#include "symbol/NewInstance.h"
#include "SymbolFactory.h"

namespace dem {
    namespace parser {
        class NewInstanceFactory : public SymbolFactory {
        public:
            static NewInstance *produce(std::deque<lexer::Token> &tokens);
        };
    }
}

#endif //DEMUSE_NEWOBJECTFACTORY_H

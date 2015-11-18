#ifndef DEMUSE_ARGUMENTLIST_H
#define DEMUSE_ARGUMENTLIST_H

#include <vector>
#include "symbol/Symbol.h"
#include "symbol/expression/Expression.h"

namespace dem {
    namespace parser {
        class ArgumentList : public Symbol {
        public:
            ArgumentList(std::vector<Expression*> arguments);

            std::vector<Expression*> &arguments();
            int numArguments();

        private:
            std::vector<Expression*> mArguments;
        };
    }
}

#endif //DEMUSE_ARGUMENTLIST_H

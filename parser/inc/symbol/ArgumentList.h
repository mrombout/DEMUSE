#ifndef DEMUSE_ARGUMENTLIST_H
#define DEMUSE_ARGUMENTLIST_H

#include <vector>
#include "symbol/Symbol.h"
#include "symbol/expression/Expression.h"

namespace dem {
    namespace parser {
        class ArgumentList : public Symbol {
        public:
            ArgumentList(const lexer::Token &token, std::vector<Expression*> arguments);

            std::vector<Expression*> &arguments();
            int numArguments();

            virtual bool accept(Visitor &visitor);

        private:
            std::vector<Expression*> mArguments;
        };
    }
}

#endif //DEMUSE_ARGUMENTLIST_H

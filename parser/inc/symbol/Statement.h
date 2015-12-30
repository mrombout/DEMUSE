#ifndef DEMUSE_STATEMENT_H
#define DEMUSE_STATEMENT_H

#include "Symbol.h"

namespace dem {
    namespace parser {
        class Statement : public Symbol {
        public:
            Statement(const lexer::Token &token);
            virtual ~Statement() = 0;
        };
    }
}

#endif //DEMUSE_STATEMENT_H

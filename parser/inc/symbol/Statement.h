#ifndef DEMUSE_STATEMENT_H
#define DEMUSE_STATEMENT_H

#include "Symbol.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents a single statement
         */
        class Statement : public Symbol {
        public:
            Statement(const lexer::Token &token);
            virtual ~Statement() = 0;
        };
    }
}

#endif //DEMUSE_STATEMENT_H

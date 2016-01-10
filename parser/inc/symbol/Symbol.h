#ifndef DEMUSE_SYMBOL_H
#define DEMUSE_SYMBOL_H

#include "Visitable.h"
#include "Token.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents a symbol
         */
        class Symbol : public Visitable {
        public:
            Symbol(const lexer::Token token);
            virtual ~Symbol() = 0;

            const lexer::Token &token() const;

        private:
            const lexer::Token mToken;
        };
    }
}

#endif //DEMUSE_SYMBOL_H

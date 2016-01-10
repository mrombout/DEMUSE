#ifndef DEMUSE_BREAK_H
#define DEMUSE_BREAK_H

#include "symbol/Statement.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents a break statement (e.g. break)
         */
        class Break : public Statement {
        public:
            Break(const lexer::Token &token);

            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_BREAK_H

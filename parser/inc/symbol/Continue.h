#ifndef DEMUSE_CONTINUE_H
#define DEMUSE_CONTINUE_H

#include "Statement.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents a continue statement (e.g. continue)
         */
        class Continue : public Statement {
        public:
            Continue(const lexer::Token &token);

            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_CONTINUE_H

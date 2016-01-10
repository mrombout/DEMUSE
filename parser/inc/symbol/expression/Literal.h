#ifndef DEMUSE_LITERAL_H
#define DEMUSE_LITERAL_H

#include "Expression.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents a literal
         *
         * A literal is a type of expression that represents a primitive that is supported by the language. For example
         * an integer could be created using just the number as its literal representative, or a string (e.g.
         * "lorum ipsum") automatically created a String object containing the given characters.
         *
         * All primitive objects in DEMUSE can be created using a literal.
         */
        class Literal : public Expression {
        public:
            Literal(const lexer::Token &token);
        };
    }
}

#endif //DEMUSE_LITERAL_H

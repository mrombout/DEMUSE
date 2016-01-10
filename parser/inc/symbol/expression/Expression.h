#ifndef DEMUSE_EXPRESSION_H
#define DEMUSE_EXPRESSION_H

#include <string>
#include "symbol/CompoundStatement.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents an expression.
         *
         * An expression, together with statements, is a very important construct of the DEMUSE scripting language. A
         * DEMUSE script is build out of one or more statements. Each statement is in turn build out of keywords and
         * expression.
         */
        class Expression : public CompoundStatement {
        public:
            Expression(const lexer::Token &token);
            virtual ~Expression() { }
        };
    }
}

#endif //DEMUSE_EXPRESSION_H

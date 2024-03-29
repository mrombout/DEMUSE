#ifndef DEMUSE_THISEXPRESSION_H
#define DEMUSE_THISEXPRESSION_H

#include "symbol/expression/Expression.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents a this expression (e.g. this)
         */
        class ThisExpression : public Expression {
        public:
            ThisExpression(const lexer::Token &token) : Expression(token) { }


            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_THISEXPRESSION_H

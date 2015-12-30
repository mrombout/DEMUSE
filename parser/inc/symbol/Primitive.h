#ifndef DEMUSE_PRIMITIVE_H
#define DEMUSE_PRIMITIVE_H

#include "expression/Expression.h"

namespace dem {
    namespace parser {
        class Primitive : public Expression {
        public:
            Primitive(const lexer::Token &token) :
                    Expression(token) {

            }
        };
    }
}

#endif //DEMUSE_PRIMITIVE_H

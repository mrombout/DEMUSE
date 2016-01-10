#ifndef DEMUSE_MODULOEXPRESSION_H
#define DEMUSE_MODULOEXPRESSION_H

#include "BinaryExpression.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents a modulo expression (e.g. 2 % 1)
         */
        class ModuloExpression : public BinaryExpression<Expression, Expression> {
        public:
            ModuloExpression(Expression *left, Expression *right);

            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_MODULOEXPRESSION_H

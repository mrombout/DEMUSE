#ifndef DEMUSE_MODULOEXPRESSION_H
#define DEMUSE_MODULOEXPRESSION_H

#include "BinaryExpression.h"

namespace dem {
    namespace parser {
        class ModuloExpression : public BinaryExpression {
        public:
            ModuloExpression(Expression *left, Expression *right);
        };
    }
}

#endif //DEMUSE_MODULOEXPRESSION_H

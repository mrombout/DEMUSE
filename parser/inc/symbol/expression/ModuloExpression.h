#ifndef DEMUSE_MODULOEXPRESSION_H
#define DEMUSE_MODULOEXPRESSION_H

#include "BinaryExpression.h"

namespace dem {
    namespace parser {
        class ModuloExpression : public BinaryExpression {
        public:
            ModuloExpression(Expression *left, Expression *right);

            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_MODULOEXPRESSION_H

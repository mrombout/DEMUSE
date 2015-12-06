#ifndef DEMUSE_PROPERTYACCESSEXPRESSION_H
#define DEMUSE_PROPERTYACCESSEXPRESSION_H

#include "symbol/expression/BinaryExpression.h"

namespace dem {
    namespace parser {
        class PropertyAccessExpression : public BinaryExpression<Expression, Expression> {
        public:
            PropertyAccessExpression(Expression *left, Expression *right);


            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_PROPERTYACCESSEXPRESSION_H

#ifndef DEMUSE_PROPERTYACCESSEXPRESSION_H
#define DEMUSE_PROPERTYACCESSEXPRESSION_H

#include "symbol/expression/BinaryExpression.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents the access of a property (e.g. foo.bar)
         * \deprecated I believe this symbol of no longer in use due to MemberExpression
         */
        class PropertyAccessExpression : public BinaryExpression<Expression, Expression> {
        public:
            PropertyAccessExpression(Expression *left, Expression *right);


            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_PROPERTYACCESSEXPRESSION_H

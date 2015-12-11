#ifndef DEMUSE_FUNCTIONCALLEXPRESSION_H
#define DEMUSE_FUNCTIONCALLEXPRESSION_H

#include <symbol/ArgumentList.h>
#include "Expression.h"

namespace dem {
    namespace parser {
        class FunctionCallExpression : public Expression {
        public:
            FunctionCallExpression(ArgumentList *argumentList, Expression *expression);

            Expression *expression() const;
            ArgumentList *argumentList() const;

            virtual bool accept(Visitor &visitor);

        private:
            Expression *mExpression;
            ArgumentList *mArgumentList;
        };
    }
}

#endif //DEMUSE_FUNCTIONCALLEXPRESSION_H

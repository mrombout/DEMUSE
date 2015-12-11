#ifndef DEMUSE_FUNCTIONCALLEXPRESSION_H
#define DEMUSE_FUNCTIONCALLEXPRESSION_H

#include "symbol/ArgumentList.h"
#include "symbol/Identifiable.h"
#include "Expression.h"

namespace dem {
    namespace parser {
        class FunctionCallExpression : public Expression, public parser::Identifiable {
        public:
            FunctionCallExpression(ArgumentList *argumentList, Expression *expression);

            virtual const std::string &name() const;

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

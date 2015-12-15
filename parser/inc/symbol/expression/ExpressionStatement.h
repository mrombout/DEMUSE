#ifndef DEMUSE_EXPRESSIONSTATEMENT_H
#define DEMUSE_EXPRESSIONSTATEMENT_H

#include "symbol/Statement.h"
#include "Expression.h"

namespace dem {
    namespace parser {
        class ExpressionStatement : public Statement {
        public:
            ExpressionStatement(Expression *expression);

            Expression &expression() const;

            virtual bool accept(Visitor &visitor);

        private:
            Expression *mExpression;
        };
    }
}

#endif //DEMUSE_EXPRESSIONSTATEMENT_H

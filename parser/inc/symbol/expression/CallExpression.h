#ifndef DEMUSE_CALLEXPRESSION_H
#define DEMUSE_CALLEXPRESSION_H

#include <vector>
#include "Expression.h"

namespace dem {
    namespace parser {
        class CallExpression : public Expression {
        public:
            CallExpression(Expression *callee, std::vector<Expression*> arguments);

            Expression &callee() const;
            const std::vector<Expression*> &arguments() const;

            virtual bool accept(Visitor &visitor);

        private:
            Expression *mCallee;
            std::vector<Expression*> mArguments;
        };
    }
}

#endif //DEMUSE_CALLEXPRESSION_H

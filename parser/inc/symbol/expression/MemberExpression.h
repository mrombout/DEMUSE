#ifndef DEMUSE_MEMBEREXPRESSION_H
#define DEMUSE_MEMBEREXPRESSION_H

#include "Expression.h"

namespace dem {
    namespace parser {
        class MemberExpression : public Expression {
        public:
            MemberExpression(Expression *object, Expression *property, bool computed);

            Expression &object() const;
            Expression &property() const;

            virtual bool accept(Visitor &visitor);

        private:
            Expression *mObject;
            Expression *mProperty;
            bool mComputed;
        };
    }
}

#endif //DEMUSE_MEMBEREXPRESSION_H

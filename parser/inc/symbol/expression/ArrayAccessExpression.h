#ifndef DEMUSE_ARRAYACCESSEXPRESSION_H
#define DEMUSE_ARRAYACCESSEXPRESSION_H

#include "Expression.h"

namespace dem {
    namespace parser {
        class ArrayAccessExpression : public Expression {
        public:
            ArrayAccessExpression(Expression *object, Expression *index, bool computed);

            Expression &object();
            Expression &index();

            virtual bool accept(Visitor &visitor);

        private:
            Expression *mObject;
            Expression *mIndex;
            bool mComputed;
        };
    }
}

#endif //DEMUSE_ARRAYACCESSEXPRESSION_H

#ifndef DEMUSE_RETURN_H
#define DEMUSE_RETURN_H

#include "symbol/Statement.h"
#include "symbol/Expression.h"

namespace dem {
    namespace parser {
        class Return : public Statement {
        public:
            Return(Expression *expression);

        private:
            Expression *mExpression;
        };
    };
}

#endif //DEMUSE_RETURN_H

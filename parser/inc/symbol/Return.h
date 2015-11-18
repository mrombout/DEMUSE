#ifndef DEMUSE_RETURN_H
#define DEMUSE_RETURN_H

#include "symbol/Statement.h"
#include "symbol/expression/Expression.h"

namespace dem {
    namespace parser {
        class Expression;
    }
}

namespace dem {
    namespace parser {
        class Return : public Statement {
        public:
            Return(Expression *expression);

        private:
            Expression *mExpression;
        public:
            virtual bool accept(Visitor &visitor) override;
        };
    };
}

#endif //DEMUSE_RETURN_H

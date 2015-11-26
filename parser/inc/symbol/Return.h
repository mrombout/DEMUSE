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

            virtual bool accept(Visitor &visitor) override;

            Expression *expression() const;

        private:
            Expression *mExpression;
        };
    };
}

#endif //DEMUSE_RETURN_H

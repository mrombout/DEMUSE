#ifndef DEMUSE_UNARYOPERATOR_H
#define DEMUSE_UNARYOPERATOR_H

#include "Expression.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents a unary expression (e.g. !true)
         */
        class UnaryExpression : public Expression {
        public:
            /**
             * \brief Constructs a UnaryExpression
             */
            UnaryExpression(lexer::Token op, Expression *argument);

            const std::string &op() const;
            Expression &argument() const;

            virtual bool accept(Visitor &visitor);

        private:
            lexer::Token mOperator;
            Expression *mArgument;
        };
    }
}

#endif //DEMUSE_UNARYOPERATOR_H

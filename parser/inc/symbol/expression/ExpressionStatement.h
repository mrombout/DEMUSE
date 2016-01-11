#ifndef DEMUSE_EXPRESSIONSTATEMENT_H
#define DEMUSE_EXPRESSIONSTATEMENT_H

#include "symbol/Statement.h"
#include "Expression.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents an expression statement (e.g. foo(), 1 + 1, a = 1 + 2, etc)
         *
         * An ExpressionStatement is simply an expression that is executed on its own. This is mainly useful for
         * expression that may have side effects such as calling of function or assigning a variable.
         */
        class ExpressionStatement : public Statement {
        public:
            /**
             * \brief Constructs a new ExpressionStatemnt
             *
             * \param expression expression to execute
             *
             * \throws std::invalid_argument if expression is null
             */
            ExpressionStatement(Expression *expression);

            Expression &expression() const;

            virtual bool accept(Visitor &visitor);

        private:
            Expression *mExpression;
        };
    }
}

#endif //DEMUSE_EXPRESSIONSTATEMENT_H

#ifndef DEMUSE_FUNCTIONCALLEXPRESSION_H
#define DEMUSE_FUNCTIONCALLEXPRESSION_H

#include "symbol/ArgumentList.h"
#include "symbol/Identifiable.h"
#include "Expression.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents a FunctionCallExpression
         * \deprecated I believe this expression is obsolete and no longer in use due to CallExpression
         */
        class FunctionCallExpression : public Expression, public parser::Identifiable {
        public:
            /**
             * \brief Constructs a new FunctionCallExpression
             *
             * \param argumentList arguments to pass to function on execution, may not be null
             * \param expression   expression to be evaluated to a callable function, may not be null
             *
             * \throws std::invalid_argument if argumentList is null
             * \throws std::invalid_argument if expression is null
             */
            FunctionCallExpression(ArgumentList *argumentList, Expression *expression);

            virtual const std::string &name() const;

            Expression &expression() const;
            ArgumentList &argumentList() const;

            virtual bool accept(Visitor &visitor);

        private:
            Expression *mExpression;
            ArgumentList *mArgumentList;
        };
    }
}

#endif //DEMUSE_FUNCTIONCALLEXPRESSION_H

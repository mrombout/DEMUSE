#ifndef DEMUSE_CALLEXPRESSION_H
#define DEMUSE_CALLEXPRESSION_H

#include <vector>
#include "Expression.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents a call expression (e.g. foo())
         *
         * A call expression is used to call a certain function of method of an object. For the expression
         * "bar(1, 2)", the callee would be an identifier "bar" pointing to a callable object (e.g. a function). For the
         * expression "foo.bar(1, 2)" the calle would be a MemberExpression to access the property "bar" of the objec
         * "foo", in turn "bar" should point to a callable object (e.g. a function).
         */
        class CallExpression : public Expression {
        public:
            /**
             * Constructs a new CallExpression.
             *
             * \param callee the object to call
             * \param arguments to pass with the call
             */
            CallExpression(Expression *callee, std::vector<Expression*> arguments);

            /**
             * \return object to call
             */
            Expression &callee() const;

            /**
             * \return list of arguments to use for the call
             */
            const std::vector<Expression*> &arguments() const;

            virtual bool accept(Visitor &visitor);

        private:
            Expression *mCallee;
            std::vector<Expression*> mArguments;
        };
    }
}

#endif //DEMUSE_CALLEXPRESSION_H

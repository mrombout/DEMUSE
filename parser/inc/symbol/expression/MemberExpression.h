#ifndef DEMUSE_MEMBEREXPRESSION_H
#define DEMUSE_MEMBEREXPRESSION_H

#include "Expression.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents the access of a member property (e.g. foo.bar)
         */
        class MemberExpression : public Expression {
        public:
            /**
             * \brief Constructs a new MemberExpression
             *
             * \param object   object to access property of, may not be null
             * \param property property to access, may not be null
             *
             * \throws std::invalid_argument if object is null
             * \throws std::invalid_argument if property is null
             */
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

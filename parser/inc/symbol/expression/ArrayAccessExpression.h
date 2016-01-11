#ifndef DEMUSE_ARRAYACCESSEXPRESSION_H
#define DEMUSE_ARRAYACCESSEXPRESSION_H

#include "Expression.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents the accessing of an array value (e.g. A[2])
         */
        class ArrayAccessExpression : public Expression {
        public:
            /**
             * \brief Produces a ArrayAccessExpression where the given index is accessed of the array
             *
             * \param array    array to access the value of
             * \param index    index of the value to access
             * \param computed ???
             *
             * \throws std::invalid_argument if array is null
             * \throws std::invalid_argument if index is null
             */
            ArrayAccessExpression(Expression *array, Expression *index, bool computed);

            // TODO: Rename getter to array for clarity
            /**
             * \return array to access the value of
             */
            Expression &object();

            /**
             * \return index of the value to access
             */
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

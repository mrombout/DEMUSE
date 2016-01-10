#ifndef DEMUSE_BINARYEXPRESSION_H
#define DEMUSE_BINARYEXPRESSION_H

#include "Expression.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents an expression that holds exactly two other expressions.
         *
         * A BinaryExpression should hold exactly two other expressions and should generaly represents a single
         * operation using those two expressions.
         *
         * It should be assumed that when the operation this BinaryExpression represent is executed, it will always be
         * executed from left to right.
         */
        template<typename TLeft, typename TRight>
        class BinaryExpression : public Expression {
        public:
            /**
             * \brief Constructs a new BinaryExpression
             *
             * \param left expression, should be executed first
             * \param right expression, should be executed last
             */
            BinaryExpression(TLeft *left, TRight *right) :
                Expression(left->token()),
                mLeft(left),
                mRight(right) {

            }

            TLeft &left() const {
                return *mLeft;
            }

            TRight &right() const {
                return *mRight;
            }

        private:
            TLeft *mLeft;
            TRight *mRight;
        };
    }
}


#endif //DEMUSE_BINARYEXPRESSION_H

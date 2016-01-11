#ifndef DEMUSE_BINARYEXPRESSION_H
#define DEMUSE_BINARYEXPRESSION_H

#include <stdexcept>
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
             * \param left expression that should be executed first, may not be null
             * \param right expression that should be executed last, may not be null
             *
             * \throws std::invalid_argument if mLeft is null
             * \throws std::invalid_argument if mRight is null
             */
            BinaryExpression(TLeft *left, TRight *right) :
                Expression(left->token()),
                mLeft(left),
                mRight(right) {
                if(!mLeft)
                    throw std::invalid_argument("Argument 'mLeft' may not be null.");
                if(!mRight)
                    throw std::invalid_argument("Argument 'mRight' may not be null.");
            }

            ~BinaryExpression() {
                delete mLeft;
                delete mRight;
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

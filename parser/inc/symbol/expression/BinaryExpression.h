#ifndef DEMUSE_BINARYEXPRESSION_H
#define DEMUSE_BINARYEXPRESSION_H

#include "Expression.h"

namespace dem {
    namespace parser {
        template<typename TLeft, typename TRight>
        class BinaryExpression : public Expression {
        public:
            BinaryExpression(TLeft *left, TRight *right) :
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

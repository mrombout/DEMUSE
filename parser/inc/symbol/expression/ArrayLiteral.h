#ifndef DEMUSE_ARRAY_H
#define DEMUSE_ARRAY_H

#include <vector>
#include "symbol/expression/Literal.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents an array literal (e.g. [0, 1, 2] )
         */
        class ArrayLiteral : public Literal {
        public:
            /**
             * \brief Constructs a new ArrayLiteral with the given expressions as its values
             *
             * \param values initial values of the array
             */
            ArrayLiteral(std::vector<Expression*> values);

            std::vector<Expression*> &expressions();

            virtual bool accept(Visitor &visitor);

        private:
            std::vector<Expression*> mValues;
        };
    }
}

#endif //DEMUSE_ARRAY_H

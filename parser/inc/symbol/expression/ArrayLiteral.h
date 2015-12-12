#ifndef DEMUSE_ARRAY_H
#define DEMUSE_ARRAY_H

#include <vector>
#include "symbol/expression/Literal.h"

namespace dem {
    namespace parser {
        class ArrayLiteral : public Literal {
        public:
            ArrayLiteral(std::vector<Expression*> values);

            std::vector<Expression*> &expressions();

            virtual bool accept(Visitor &visitor);

        private:
            std::vector<Expression*> mValues;
        };
    }
}

#endif //DEMUSE_ARRAY_H

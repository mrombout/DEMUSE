#ifndef DEMUSE_ARRAY_H
#define DEMUSE_ARRAY_H

#include <vector>
#include "symbol/expression/Expression.h"

namespace dem {
    namespace parser {
        class Array : public Expression {
        public:
            Array(std::vector<Expression*> values);

            std::vector<Expression*> &expressions();

            virtual bool accept(Visitor &visitor);

        private:
            std::vector<Expression*> mValues;
        };
    }
}

#endif //DEMUSE_ARRAY_H

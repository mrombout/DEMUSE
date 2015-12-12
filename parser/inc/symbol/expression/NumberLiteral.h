#ifndef DEMUSE_NUMBER_H
#define DEMUSE_NUMBER_H

#include <string>
#include "Literal.h"

namespace dem {
    namespace parser {
        class NumberLiteral : public Literal {
        public:
            NumberLiteral(double value);

            virtual bool accept(Visitor &visitor);

            double value() const;

        private:
            double mValue;
        };
    }
}

#endif //DEMUSE_NUMBER_H

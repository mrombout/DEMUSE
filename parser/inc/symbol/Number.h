#ifndef DEMUSE_NUMBER_H
#define DEMUSE_NUMBER_H

#include <string>
#include "Primitive.h"

namespace dem {
    namespace parser {
        class Number : public Primitive {
        public:
            Number(double value);

            virtual bool accept(Visitor &visitor);

            double value() const;

        private:
            double mValue;
        };
    }
}

#endif //DEMUSE_NUMBER_H

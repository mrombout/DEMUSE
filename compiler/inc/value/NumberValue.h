#ifndef DEMUSE_NUMBERVALUE_H
#define DEMUSE_NUMBERVALUE_H

#include "Value.h"

namespace dem {
    namespace compiler {
        class NumberValue : public Value {
        public:
            NumberValue(double value);

            virtual std::string toString();

        private:
            double mValue;
        };
    }
}

#endif //DEMUSE_NUMBERVALUE_H

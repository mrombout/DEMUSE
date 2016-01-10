#ifndef DEMUSE_PRINTFUNCTION_H
#define DEMUSE_PRINTFUNCTION_H

#include "value/function/InternalFunction.h"

namespace dem {
    namespace compiler {
        /**
         * \brief Prints out first parameter to std::cout
         *
         * Prints out the first parameter to std::cout.
         *
         * Parameters:
         *  - String: String to print out
         *
         * Returns:
         *  - Null
         */
        class PrintFunction : public InternalFunction {
        public:
            PrintFunction(ObjectValue *parent);

            virtual Value *operator()();
        };
    }
}

#endif //DEMUSE_PRINTFUNCTION_H

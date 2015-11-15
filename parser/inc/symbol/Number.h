#ifndef DEMUSE_NUMBER_H
#define DEMUSE_NUMBER_H

#include <string>
#include "Primitive.h"

namespace dem {
    namespace parser {
        class Number : public Primitive {
        public:
            Number(std::string value);

        private:
            std::string mValue;
        };
    }
}

#endif //DEMUSE_NUMBER_H

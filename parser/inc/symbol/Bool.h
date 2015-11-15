#ifndef DEMUSE_BOOL_H
#define DEMUSE_BOOL_H

#include <string>
#include "Primitive.h"

namespace dem {
    namespace parser {
        class Bool : public Primitive {
        public:
            Bool(std::string value);

        private:
            std::string mValue;
        };
    }
}

#endif //DEMUSE_BOOL_H

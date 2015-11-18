#ifndef DEMUSE_BOOL_H
#define DEMUSE_BOOL_H

#include <string>
#include "Primitive.h"

namespace dem {
    namespace parser {
        class Bool : public Primitive {
        public:
            Bool(std::string value);

            std::string value() const;

        private:
            std::string mValue;
        public:
            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_BOOL_H

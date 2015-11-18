#ifndef DEMUSE_NUMBER_H
#define DEMUSE_NUMBER_H

#include <string>
#include "Primitive.h"

namespace dem {
    namespace parser {
        class Number : public Primitive {
        public:
            Number(std::string value);

            std::string value() const;

        private:
            std::string mValue;
        public:
            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_NUMBER_H

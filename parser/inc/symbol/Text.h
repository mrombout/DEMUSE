#ifndef DEMUSE_TEXT_H
#define DEMUSE_TEXT_H

#include <string>
#include "Primitive.h"

namespace dem {
    namespace parser {
        class Text : public Primitive {
        public:
            Text(std::string value);

            std::string value() const;

        private:
            std::string mValue;
        public:
            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_TEXT_H

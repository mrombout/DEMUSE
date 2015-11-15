#ifndef DEMUSE_TEXT_H
#define DEMUSE_TEXT_H

#include <string>
#include "Primitive.h"

namespace dem {
    namespace parser {
        class Text : public Primitive {
        public:
            Text(std::string content);

        private:
            std::string mContent;
        };
    }
}

#endif //DEMUSE_TEXT_H

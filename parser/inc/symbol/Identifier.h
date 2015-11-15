#ifndef DEMUSE_IDENTIFIER_H
#define DEMUSE_IDENTIFIER_H

#include <string>
#include "Symbol.h"

namespace dem {
    namespace parser {
        class Identifier : public Symbol {
        public:
            Identifier(std::string name);

        private:
            std::string mName;
        };
    }
}

#endif //DEMUSE_IDENTIFIER_H

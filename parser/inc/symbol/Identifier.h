#ifndef DEMUSE_IDENTIFIER_H
#define DEMUSE_IDENTIFIER_H

#include <string>
#include "expression/Expression.h"

namespace dem {
    namespace parser {
        class Identifier : public Expression {
        public:
            Identifier(std::string name);

        private:
            std::string mName;
        public:
            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_IDENTIFIER_H

#ifndef DEMUSE_IDENTIFIER_H
#define DEMUSE_IDENTIFIER_H

#include <string>
#include <symbol/play/Playable.h>
#include "expression/Expression.h"

namespace dem {
    namespace parser {
        class Identifier : public Expression {
        public:
            Identifier(std::string name);

            virtual bool accept(Visitor &visitor);

            virtual const std::string &name() const;

        private:
            std::string mName;
        };
    }
}

#endif //DEMUSE_IDENTIFIER_H

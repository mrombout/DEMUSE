#ifndef DEMUSE_PARAMETERLIST_H
#define DEMUSE_PARAMETERLIST_H

#include <vector>
#include "Symbol.h"
#include "Identifier.h"

namespace dem {
    namespace parser {
        class Identifier;
    }
}

namespace dem {
    namespace parser {
        class ParameterList : public Symbol {
        public:
            ParameterList(std::vector<Identifier*> identifiers);

        private:
            std::vector<Identifier*> mIdentifiers;
        public:
            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_PARAMETERLIST_H

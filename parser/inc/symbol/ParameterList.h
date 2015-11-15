#ifndef DEMUSE_PARAMETERLIST_H
#define DEMUSE_PARAMETERLIST_H

#include <vector>
#include "Symbol.h"
#include "Identifier.h"

namespace dem {
    namespace parser {
        class ParameterList : public Symbol {
        public:
            ParameterList(std::vector<Identifier*> identifiers);

        private:
            std::vector<Identifier*> mIdentifiers;
        };
    }
}

#endif //DEMUSE_PARAMETERLIST_H

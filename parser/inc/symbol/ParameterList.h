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
        /**
         * \brief Represents a parameter list for a function or new object (e.g. foo, bar)
         */
        class ParameterList : public Symbol {
        public:
            ParameterList(const lexer::Token &token);
            ParameterList(std::vector<Identifier*> identifiers);
            ~ParameterList();

            virtual bool accept(Visitor &visitor);

            std::vector<Identifier*> parameters() const;
            int numParameters() const;
            bool isEmpty() const;

        private:
            std::vector<Identifier*> mIdentifiers;
        };
    }
}

#endif //DEMUSE_PARAMETERLIST_H

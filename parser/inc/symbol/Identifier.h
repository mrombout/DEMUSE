#ifndef DEMUSE_IDENTIFIER_H
#define DEMUSE_IDENTIFIER_H

#include <string>
#include "expression/Expression.h"
#include "Identifiable.h"

namespace dem {
    namespace parser {
        class Identifier : public Expression, public parser::Identifiable {
        public:
            Identifier(std::string name);

            virtual bool accept(Visitor &visitor);

            virtual const std::string &name() const override;

        private:
            std::string mName;
        };
    }
}

#endif //DEMUSE_IDENTIFIER_H

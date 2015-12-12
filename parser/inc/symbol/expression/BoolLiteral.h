#ifndef DEMUSE_BOOL_H
#define DEMUSE_BOOL_H

#include <string>
#include "Literal.h"

namespace dem {
    namespace parser {
        class BoolLiteral : public Literal {
        public:
            BoolLiteral(bool value);

            virtual bool accept(Visitor &visitor);

            bool value() const;

        private:
            bool mValue;
        };
    }
}

#endif //DEMUSE_BOOL_H

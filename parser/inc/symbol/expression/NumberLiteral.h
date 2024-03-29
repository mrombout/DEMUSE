#ifndef DEMUSE_NUMBER_H
#define DEMUSE_NUMBER_H

#include <string>
#include "Literal.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents a number literal (e.g. 1 or 1.4, etc)
         */
        class NumberLiteral : public Literal {
        public:
            NumberLiteral(lexer::Token &token, double value);

            virtual bool accept(Visitor &visitor);

            double value() const;

        private:
            double mValue;
        };
    }
}

#endif //DEMUSE_NUMBER_H

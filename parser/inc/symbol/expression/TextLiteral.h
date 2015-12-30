#ifndef DEMUSE_TEXT_H
#define DEMUSE_TEXT_H

#include <string>
#include "symbol/expression/Literal.h"

namespace dem {
    namespace parser {
        class TextLiteral : public Literal {
        public:
            TextLiteral(const lexer::Token &token, std::string value);

            std::string value() const;

        private:
            std::string mValue;
        public:
            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_TEXT_H

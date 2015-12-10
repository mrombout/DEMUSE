#ifndef DEMUSE_TOKEN_H
#define DEMUSE_TOKEN_H

#include <string>
#include "TokenType.h"
#include "TokenPosition.h"

namespace dem {
    namespace lexer {
        class Token {
        public:
            Token(const TokenType type, std::string content, TokenPosition tokenPosition);

            const TokenType &type() const;
            const bool is(TokenType tokenType) const;

            const std::string &content() const;
            void setContent(std::string content);
            const int startIndex() const;
            const int line() const;
            const int column() const;

        private:
            const TokenType mType;
            std::string mContent;

            TokenPosition mTokenPosition;
        };
    }
}

#endif //DEMUSE_TOKEN_H

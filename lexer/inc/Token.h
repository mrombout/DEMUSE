#ifndef DEMUSE_TOKEN_H
#define DEMUSE_TOKEN_H

#include <string>
#include "TokenType.h"

namespace dem {
    namespace lexer {
        class Token {
        public:
            Token(const TokenType type, std::string content, int startIndex, int line, int column);

            const TokenType &type() const;
            const std::string &content() const;
            void setContent(std::string content);
            const int startIndex() const;
            const int line() const;
            const int column() const;

        private:
            const TokenType mType;
            std::string mContent;

            int mStartIndex;
            int mLine;
            int mColumn;
        };
    }
}

#endif //DEMUSE_TOKEN_H

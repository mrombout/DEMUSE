#include <string>
#include "Token.h"

namespace dem {
    namespace lexer {
        Token::Token(const TokenType type, std::string content, int startIndex, int line, int column) :
            mType(type),
            mContent(content),
            mStartIndex(startIndex),
            mLine(line),
            mColumn(column) {

        }

        const TokenType &Token::type() const {
            return mType;
        }

        const std::string &Token::content() const {
            return mContent;
        }

        void Token::setContent(std::string content) {
            mContent = content;
        }

        const int Token::startIndex() const {
            return mStartIndex;
        }

        const int Token::line() const {
            return mLine;
        }

        const int Token::column() const {
            return mColumn;
        }
    }
}

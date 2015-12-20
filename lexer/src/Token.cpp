#include <string>
#include "Token.h"

namespace dem {
    namespace lexer {
        const Token Token::NULL_TOKEN(TokenType::UNKNOWN, "", TokenPosition());

        Token::Token(const TokenType type, std::string content, TokenPosition tokenPosition) :
            mType(type),
            mContent(content),
            mTokenPosition(tokenPosition) {

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
            return mTokenPosition.index;
        }

        const int Token::line() const {
            return mTokenPosition.line;
        }

        const int Token::column() const {
            return mTokenPosition.column;
        }

        const bool Token::is(TokenType tokenType) const {
            return mType == tokenType;
        }

        const bool Token::isEOF() const {
            return is(TokenType::ENDOFFILE);
        }
    }
}

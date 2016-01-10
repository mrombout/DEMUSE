#ifndef DEMUSE_TOKEN_H
#define DEMUSE_TOKEN_H

#include <string>
#include "TokenType.h"
#include "TokenPosition.h"

namespace dem {
    namespace lexer {
        class Token {
        public:
            /**
             * \brief Contains all information about a particular DEMUSE language construct.
             *
             * A token contains all information about a particular DEMUSE language construct. A token could be seen as
             * words and punction in the English language. Tokens are mainly used by the parser to build the correct
             * parse tree. But also for relaying useful error messages to the user.
             *
             * \param type          the tokentype this token represents
             * \param content       the content of this token
             * \param tokenPosition the position of this token in the script
             */
            Token(TokenType type, std::string content, TokenPosition tokenPosition);

            /**
             * \brief Returns the type of this token.
             *
             * \return type of this token
             */
            const TokenType &type() const;

            /**
             * \brief Returns whether this token is of the given type.
             *
             * \param tokenType token type to check
             * \return whether this token is of the given type
             */
            const bool is(TokenType tokenType) const;

            /**
             * \brief Returns whether this token is an END_OF_FILE token.
             *
             * \return whether this token is an END_OF_FILE token
             */
            const bool isEOF() const;

            /**
             * \brief Returns the content of this token.
             *
             * \return content of this token
             */
            const std::string &content() const;

            /**
             * \brief Sets the content of this token.
             *
             * \param content the content of this token
             */
            void setContent(std::string content);

            /**
             * \brief Returns the start index of this token. The index is the character index in the entire file, starting at
             * zero.
             *
             * \return start index of this token
             */
            const int startIndex() const;

            /**
             * \brief Returns the line of this token. The line numbers in a file starts at 1.
             *
             * \return the line of this token
             */
            const int line() const;

            /**
             * \brief Returns the column of this token. The column is the character index on a single line, starting at 1.
             *
             * \return the column of this token
             */
            const int column() const;

        public:
            static const Token NULL_TOKEN;

        private:
            TokenType mType;
            std::string mContent;

            TokenPosition mTokenPosition;
        };
    }
}

#endif //DEMUSE_TOKEN_H

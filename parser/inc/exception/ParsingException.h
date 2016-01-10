#ifndef DEMUSE_PARSINGEXCEPTION_H
#define DEMUSE_PARSINGEXCEPTION_H

#include <exception>
#include "Token.h"

namespace dem {
    namespace parser {
        /**
         * \brief Exception thrown when an error occurs during the parsing of a DEMUSE script.
         */
        class ParsingException : public std::exception {
        public:
            ParsingException(const lexer::Token &token, const std::string msg);

            const lexer::Token &token() const;

            virtual const char *what() const noexcept override;

        private:
            const lexer::Token &mToken;
            const std::string mMsg;
        };
    }
}

#endif //DEMUSE_PARSINGEXCEPTION_H

#ifndef DEMUSE_PARSINGEXCEPTION_H
#define DEMUSE_PARSINGEXCEPTION_H

#include <exception>
#include "Token.h"

namespace dem {
    namespace parser {
        class ParsingException : public std::exception {
        public:
            ParsingException(lexer::Token &token, const std::string msg);

            const lexer::Token &token() const;

            virtual const char *what() const noexcept override;

        private:
            lexer::Token &mToken;
            const std::string mMsg;
        };
    }
}

#endif //DEMUSE_PARSINGEXCEPTION_H

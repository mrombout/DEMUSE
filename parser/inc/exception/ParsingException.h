#ifndef DEMUSE_PARSINGEXCEPTION_H
#define DEMUSE_PARSINGEXCEPTION_H

#include <exception>
#include "Token.h"

namespace dem {
    namespace parser {
        class ParsingException : public std::exception {
        public:
            ParsingException();
            ParsingException(lexer::Token &token);
        };
    }
}

#endif //DEMUSE_PARSINGEXCEPTION_H

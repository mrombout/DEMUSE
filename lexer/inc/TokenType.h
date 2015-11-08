#ifndef DEMUSE_TOKENTYPE_H
#define DEMUSE_TOKENTYPE_H

#include <iostream>

namespace dem {
    namespace lexer {
        enum class TokenType {
            BOOL,
            TEXT,
            NUMBER,
            COMMA,
            PERIOD,
            POSITIVE,
            NEGATIVE,
            PLUS,
            MINUS,
            TIMES,
            DIVIDE,
            EQ,
            NEQ,
            SM,
            SMEQ,
            LR,
            LREQ,
            NOT,
            OR,
            AND,
            FOREACH,
            IN,
            ELSE,
            IF,
            WHILE,
            CONTINUE,
            BREAK,
            RETURN,
            START,
            END,
            OPEN,
            CLOSE,
            FUNCTION,
            VAR,
            TERMINATOR,
            ASSIGNMENT,
            IDENTIFIER,
            UNKNOWN
        };

        std::ostream & operator<<(std::ostream &output, const TokenType &tokenType);
    }
}

#endif //DEMUSE_TOKENTYPE_H
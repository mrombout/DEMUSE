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
            MOD,
            EQ,
            TEQ,
            NEQ,
            TNEQ,
            SM,
            SMEQ,
            LR,
            LREQ,
            NOT,
            OR,
            AND,
            FOR,
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
            BRACKET_OPEN,
            BRACKET_CLOSE,
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

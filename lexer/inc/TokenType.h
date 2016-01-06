#ifndef DEMUSE_TOKENTYPE_H
#define DEMUSE_TOKENTYPE_H

#include <cstdint>
#include <iostream>

namespace dem {
    namespace lexer {
        enum class TokenType : std::int8_t {
            BOOL = 1,
            TEXT,
            NUMBER,
            THIS_T,
            COMMA,
            PERIOD,
            POSITIVE,
            NEGATIVE,
            PLUS,
            MINUS,
            TIMES,
            DIVIDE,
            MOD,
            EXP,
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
            IN_ARRAY,
            ELSE,
            NEW,
            IF,
            WHILE,
            CONTINUE,
            BREAK,
            RETURN,
            TRACK,
            NOTE,
            ACCIDENTAL,
            CHORD,
            DURATION,
            HARMONY,
            MEASURE,
            TUPLET,
            TIE,
            ATTACK,
            DECAY,
            COMBINE,
            KEY,
            INSTRUMENT,
            VOICE,
            LAYER,
            TEMPO,
            PITCH,
            PRESSURE,
            POLY_PRESSURE,
            CONTROLLER,
            TIME,
            START,
            END,
            OPEN,
            CLOSE,
            BRACKET_OPEN,
            BRACKET_CLOSE,
            PLAY_START,
            PLAY_END,
            FUNCTION,
            VAR,
            TERMINATOR,
            ASSIGNMENT,
            IDENTIFIER,
            UNKNOWN,
            SINGLECOMMENT,
            MULTICOMMENT,
            ENDOFFILE
        };

        std::ostream & operator<<(std::ostream &output, const TokenType &tokenType);
    }
}

#endif //DEMUSE_TOKENTYPE_H

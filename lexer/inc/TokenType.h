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
            IN,
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
            OCTAVE,
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
            PLAY,
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

#include "factory/PrimitiveFactory.h"
#include "symbol/Bool.h"
#include "symbol/Text.h"
#include "symbol/Number.h"

namespace dem {
    namespace parser {
        Primitive *PrimitiveFactory::produce(std::deque<lexer::Token> &tokens) {
            // primitive = bool | text | number | note
            // bool      = "true" | "false"
            // text      = '"' { ? any utf8_char except unescaped '"' ? | escape } '"' ;
            // number    = integer | double ;
            // integer   = nonzero { digit } | zero ;
            // double    = [ integer ] fraction ;
            // fraction  = "," { digit } ;
            // note      = ( ( "C" | "C#" | "D" | "D#" | "E" | "F" | "F#" | "G" | "G#" | "A" | "A#" | "B" ) [ integer ] | "R" ) [ "w" | "h" | "q" ] ;

            // bool
            lexer::Token token = tokens.front();
            if(tokens.front().is(lexer::TokenType::BOOL)) {
                tokens.pop_front();
                return new Bool(token.content());
            } else if(tokens.front().is(lexer::TokenType::TEXT)) {
                tokens.pop_front();
                return new Text(token.content());
            } else if(tokens.front().is(lexer::TokenType::NUMBER)) {
                tokens.pop_front();
                return new Number(token.content());
            }

            // TODO: Note

            return nullptr;
        }
    }
}

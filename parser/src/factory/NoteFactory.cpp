#include "factory/NoteFactory.h"
#include "exception/ParsingException.h"

namespace dem {
    namespace parser {
        Note *NoteFactory::produce(std::deque<lexer::Token> &tokens) {
            // note = ( ( "C" | "D" | "E" | "F" | "G" | "A" | "B" ) [ integer ] [ "#" | "b" | "n" ] | "R" ) [ "w" | "h" | "q" ] ;

            if(!tokens.front().is(lexer::TokenType::NOTE)) {
                throw new ParsingException();
            }

            tokens.pop_front();

            return new Note();
        }
    }
}

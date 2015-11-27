#include "symbol/play/Note.h"
#include "factory/NoteFactory.h"

namespace dem {
    namespace parser {
        Note *NoteFactory::produce(std::deque<lexer::Token> &tokens) {
            // note = ( ( "C" | "C#" | "D" | "D#" | "E" | "F" | "F#" | "G" | "G#" | "A" | "A#" | "B" ) [ integer ] | "R" ) [ "w" | "h" | "q" ] ;

            expect(tokens, lexer::TokenType::NOTE);

            return new Note();
        }
    }
}

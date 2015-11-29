#include "factory/NoteFactory.h"
#include "exception/ParsingException.h"

namespace dem {
    namespace parser {
        Note *NoteFactory::produce(std::deque<lexer::Token> &tokens) {
            // note = ( ( "C" | "D" | "E" | "F" | "G" | "A" | "B" ) [ integer ] [ "#" | "b" | "n" ] | "R" ) [ "w" | "h" | "q" ] ;

            // note
            if(!tokens.front().is(lexer::TokenType::NOTE)) {
                throw new ParsingException();
            }
            NoteT note = tokens.front().content().at(0);
            tokens.pop_front();

            // octave
            Octave octave = 5;
            if(tokens.front().is(lexer::TokenType::OCTAVE)) {
                octave = atoi(tokens.front().content().c_str());
                tokens.pop_front();
            }

            // accidental
            Accidental accidental = 'n';
            if(tokens.front().is(lexer::TokenType::ACCIDENTAL)) {
                accidental = tokens.front().content().at(0);
                tokens.pop_front();
            }

            // duration
            Duration duration = 'w';
            if(tokens.front().is(lexer::TokenType::DURATION)) {
                duration = tokens.front().content().at(0);
                tokens.pop_front();
            }

            return new Note(note, octave, accidental, duration);
        }
    }
}

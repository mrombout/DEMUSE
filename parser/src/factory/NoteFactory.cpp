#include "factory/NoteFactory.h"

namespace dem {
    namespace parser {
        Note *NoteFactory::produce(std::deque<lexer::Token> &tokens, ParseResults &results) {
            // note = ( ( "C" | "D" | "E" | "F" | "G" | "A" | "B" ) [ integer ] [ "#" | "b" | "n" ] | "R" ) [ "w" | "h" | "q" ] ;

            lexer::Token token = tokens.front();

            // note
            expect(tokens, lexer::TokenType::NOTE, results, false);
            NoteT note = tokens.front().content().at(0);
            tokens.pop_front();

            // octave
            Octave octave = 5;
            if(tokens.front().is(lexer::TokenType::NUMBER)) {
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

            return new Note(token, note, octave, accidental, duration);
        }
    }
}

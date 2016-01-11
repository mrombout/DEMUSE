#include <sstream>
#include <c++/stdexcept>
#include "symbol/play/Note.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Note::Note(const lexer::Token &token, NoteT note, Octave octave, Accidental accidental, Duration duration) :
            Playable(token),
            mNote(note),
            mOctave(octave),
            mAccidental(accidental),
            mDuration(duration) {
            if(mNote < 'A' || mNote > 'G')
                throw std::invalid_argument("Argument 'note' may only range from 'A' to 'G', note '" + std::to_string(mNote) + "' is not allowed.");
            if(mOctave < 0 || mOctave > 10)
                throw std::invalid_argument("Argument 'octave' may only range from '0' to '10', octave '" + std::to_string(mOctave) + "' is not allowed.");
        }

        bool Note::accept(Visitor &visitor) {
            return visitor.visit(*this);
        }

        NoteT Note::note() const {
            return mNote;
        }

        Octave Note::octave() const {
            return mOctave;
        }

        Accidental Note::accidental() const {
            return mAccidental;
        }

        Duration Note::duration() const {
            return mDuration;
        }

        int Note::midiNote() const {
            int midiNote = 0;

            // note base values (octave 0)
            if(note() == 'C') {
                midiNote = 0;
            } else if(note() == 'D') {
                midiNote = 2;
            } else if(note() == 'E') {
                midiNote = 4;
            } else if(note() == 'F') {
                midiNote = 5;
            } else if(note() == 'G') {
                midiNote = 7;
            } else if(note() == 'A') {
                midiNote = 9;
            } else if(note() == 'B') {
                midiNote = 11;
            }

            // octave (every octave adds 12)
            midiNote += (octave() * 12);

            // accidental
            if(accidental() == '#') {
                midiNote += 1;
            } else if(accidental() == 'b') {
                midiNote -= 1;
            }

            return midiNote;
        }

        int Note::midiDuration() const {
            // decide note length
            int noteDuration = 4; // default to whole
            if(duration() == 'h') {        // half
                noteDuration = 2;
            } else if(duration() == 'q') { // quarter
                noteDuration = 1;
            } else if(duration() == 'i') { // eighth
                noteDuration = 1 / 2;
            } else if(duration() == 's') { // sixteenth
                noteDuration = 1 / 2 / 2;
            } else if(duration() == 't') {  // thirty-second
                noteDuration = 1 / 2 / 2 / 2;
            } else if(duration() == 'x') { // sixty-fourth
                noteDuration = 1 / 2 / 2 / 2 / 2;
            } else if(duration() == 'o') { // one-twenty-eighth
                noteDuration = 1 / 2 / 2 / 2 / 2 / 2;
            }

            return noteDuration;
        }

        std::string Note::toString() const {
            std::stringstream ss;

            ss << mNote << mOctave << mAccidental << mDuration;

            return ss.str();
        }
    }
}

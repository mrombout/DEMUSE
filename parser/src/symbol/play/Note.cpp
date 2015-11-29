#include "symbol/play/Note.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Note::Note(NoteT note, Octave octave, Accidental accidental, Duration duration) :
            mNote(note),
            mOctave(octave),
            mAccidental(accidental),
            mDuration(duration) {

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
    }
}

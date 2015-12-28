#ifndef DEMUSE_NOTE_H
#define DEMUSE_NOTE_H

#include <string>
#include "symbol/Primitive.h"
#include "Playable.h"

namespace dem {
    namespace parser {
        typedef char NoteT;
        typedef int Octave;
        typedef char Accidental;
        typedef char Duration;

        class Note : public Playable {
        public:
            Note(NoteT note, Octave octave, Accidental accidental = 'n', Duration duration = 'w');

            NoteT note() const;
            Octave octave() const;
            Accidental accidental() const;
            Duration duration() const;

            int midiNote() const;
            int midiDuration() const;

            virtual bool accept(Visitor &visitor);

        private:
            NoteT mNote;
            Octave mOctave;
            Accidental mAccidental;
            Duration mDuration;
        };
    }
}

#endif //DEMUSE_NOTE_H

#ifndef DEMUSE_NOTE_H
#define DEMUSE_NOTE_H

#include <string>
#include "symbol/Primitive.h"
#include "Playable.h"

namespace dem {
    namespace parser {
        // TODO: Replace typdefs with enum
        typedef char NoteT;
        typedef int Octave;
        typedef char Accidental;
        typedef char Duration;

        /**
         * \brief Represents a single note (e.g. C#q)
         */
        class Note : public Playable {
        public:
            /**
             * \brief Constructs a new Note
             *
             * \param token      token this note is represented by
             * \param note       note ranging from 'A' to 'G'
             * \param octave     octave ranging from 0 to 10
             * \param accidental defaults to *n*atural, see EBNF for a list of allowed accidentals
             * \param duration   defaults to *w*hole, see EBNF for a list of allowed durations
             *
             * \throws std::invalid_argument if note is not between 'A' and 'G'
             * \throws std::invalid_argument if octave is not between 0 and 10
             */
            Note(const lexer::Token &token, NoteT note, Octave octave, Accidental accidental = 'n', Duration duration = 'w');

            /**
             * \brief Returns the note of this Note
             *
             * Returns only the note of this Note, octave and other properties are not included. A note only ranges from
             * 'A' to 'G'.
             *
             * \return note of this Note
             */
            NoteT note() const;

            /**
             * \brief Returns the octave of this note
             *
             * Returns the octave of this note ranging from 0 to 10.
             *
             * \return octave of this Note, ranging from 0 to 10
             */
            Octave octave() const;

            /**
             * \brief Returns the accidental of this note.
             *
             * Returns the accidental of this note. The accidental is represented as the same character used in DEMUSE
             * script. Please refer to the user manual for more information.
             *
             * \return accidental of this note
             */
            Accidental accidental() const;

            /**
             * \brief Returns the duration of this note.
             *
             * Returns the duration of this note. The duration is represented as the same character used in DEMUSE
             * script. Please refer to the user manual for more information.
             *
             * \return duration of this note
             */
            Duration duration() const;

            /**
             * \brief Returns the midi note index for this note in it's correct octave
             *
             * MIDI uses a sequential series of numbers to represent each possible note, this is often refered to as the
             * MIDI number. The specifications define note number 60 as "Middle C", all other note values are relative.
             */
            int midiNote() const;

            /**
             * \brief Returns the duration to be used in a midi file
             *
             * TODO: We can't assume a measure of 4, perhaps provide a way to take measure as argument?
             *
             * Returns the duration of a note relative to a whole note in a measure of 4. For example for a (w)hole note
             * this method will return 4, for a (h)alf note this method will return 2 or 4 / 2. For a quarter note this
             * method will return 1 or 4 / 4).
             *
             * \return duration relative to a 4/4 measure
             */
            int midiDuration() const;

            /**
             * \brief Returns the string representation of this note
             *
             * Returns the string representation of this note exactly how it is represented in DEMUSE script. Please
             * refer to the user manual for more information.
             *
             * \return string representation of this note
             */
            std::string toString() const;

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

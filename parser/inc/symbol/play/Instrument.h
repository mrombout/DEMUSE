#ifndef DEMUSE_INSTRUMENT_H
#define DEMUSE_INSTRUMENT_H

#include "Playable.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents an instrument change (e.g. I[1])
         *
         * When compiled to MIDI the instrument index corresponds to the
         * [General MIDI Level 1 Instrument Patch Map](http://www.midi.org/techspecs/gm1sound.php), based on a 0 index.
         *
         * A list of available instrument is also defined in the Song object as separate variables. Please refer to the
         * user manual.
         */
        class Instrument : public Playable {
        public:
            /**
             * \brief Constructs a new Instrument chance
             *
             * \param instrumentExpression expression that determines the instrument index
             * \throws std::invalid_argument if instrumentExpression is null
             */
            Instrument(Expression *instrumentExpression);

            Expression &instrumentExpression();

            virtual bool accept(Visitor &visitor);

        private:
            Expression *mInstrumentExpression;
        };
    }
}

#endif //DEMUSE_INSTRUMENT_H

#ifndef DEMUSE_TRACK_H
#define DEMUSE_TRACK_H

#include "Statement.h"
#include "Block.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents a track
         *
         * A track is used to play several tunes and notes simultaneously. A track 1 may, for example contain a series
         * of C notes, while track 2 contains a series of D notes. When played both the notes C and D will be played
         * together.
         *
         * Depending on the compiler used a track may also mean something more significant. For example when the Module
         * compiler is used, each track directly maps to a track in the mod file.
         */
        class Track : public Statement {
        public:
            Track(int channel, Block *block);

            int channel() const;
            const Block &block() const;

            virtual bool accept(Visitor &visitor);

        private:
            int mChannel;
            Block *mBlock;
        };
    }
}

#endif //DEMUSE_TRACK_H

#ifndef DEMUSE_TRACK_H
#define DEMUSE_TRACK_H

#include "Statement.h"
#include "Block.h"

namespace dem {
    namespace parser {
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

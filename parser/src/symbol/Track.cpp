#include "symbol/Track.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Track::Track(int channel, Block *block) :
            mChannel(channel),
            mBlock(block) {

        }

        int Track::channel() const {
            return mChannel;
        }

        const Block &Track::block() const {
            return *mBlock;
        }

        bool Track::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                mBlock->accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}
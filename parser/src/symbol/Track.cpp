#include <stdexcept>
#include "symbol/Track.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Track::Track(int channel, Block *block) :
            Statement(block->token()),
            mChannel(channel),
            mBlock(block) {
            if(!mBlock)
                throw std::invalid_argument("Argument 'block' may not be null.");
        }

        Track::~Track() {
            delete mBlock;
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
#include "symbol/Program.h"
#include "symbol/Statement.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Program::Program(std::vector<Track*> tracks) :
            mTracks(tracks) {

        }

        Program::~Program() {

        }

        const std::vector<Track*> &Program::tracks() const {
            return mTracks;
        }

        bool Program::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                for(Track *track : mTracks) {
                    track->accept(visitor);
                }
            }

            return visitor.visitLeave(*this);
        }
    }
}
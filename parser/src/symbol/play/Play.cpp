#include "symbol/play/Play.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Play::Play(std::vector<Note*> notes) :
                mNotes(notes) {

        }

        bool Play::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                for(Note *note : mNotes) {
                    note->accept(visitor);
                }
            }

            return visitor.visitLeave(*this);
        }

        const std::vector<Note*> Play::notes() const {
            return mNotes;
        }
    }
}

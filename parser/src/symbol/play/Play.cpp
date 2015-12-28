#include "symbol/play/Play.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Play::Play(std::vector<Expression*> playables) :
                mPlayables(playables) {

        }

        bool Play::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                for(Expression *playable : mPlayables) {
                    playable->accept(visitor);
                }
            }

            return visitor.visitLeave(*this);
        }

        const std::vector<Expression*> Play::playables() const {
            return mPlayables;
        }
    }
}

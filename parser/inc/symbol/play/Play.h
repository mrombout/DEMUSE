#ifndef DEMUSE_PLAY_H
#define DEMUSE_PLAY_H

#include <vector>
#include "symbol/Statement.h"
#include "Note.h"

namespace dem {
    namespace parser {
        class Play : public Statement {
        public:
            Play(std::vector<Note*> tokens) :
                    mTokens(tokens) {

            }

            virtual bool accept(Visitor &visitor);

        private:
            std::vector<Note*> mTokens;
        };
    }
}

#endif //DEMUSE_PLAY_H

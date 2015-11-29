#ifndef DEMUSE_PLAY_H
#define DEMUSE_PLAY_H

#include <vector>
#include "symbol/Statement.h"
#include "Note.h"

namespace dem {
    namespace parser {
        class Play : public Statement {
        public:
            Play(std::vector<Note*> notes);

            const std::vector<Note*> notes() const;

            virtual bool accept(Visitor &visitor);

        private:
            std::vector<Note*> mNotes;
        };
    }
}

#endif //DEMUSE_PLAY_H

#ifndef DEMUSE_PROGRAM_H
#define DEMUSE_PROGRAM_H

#include <vector>
#include "symbol/Symbol.h"

namespace dem {
    namespace parser {
        class Track;
    }
}

namespace dem {
    namespace parser {
        class Program : public Symbol {
        public:
            Program(std::vector<Track*> statements);
            virtual ~Program();

            const std::vector<Track*> &tracks() const;

            virtual bool accept(Visitor &visitor);

        private:
            std::vector<Track*> mTracks;
        };
    }
}

#endif //DEMUSE_PROGRAM_H

#ifndef DEMUSE_PLAY_H
#define DEMUSE_PLAY_H

#include "symbol/Statement.h"

namespace dem {
    namespace parser {
        class Play : public Statement {

        public:
            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_PLAY_H

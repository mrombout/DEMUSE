#ifndef DEMUSE_PLAYABLE_H
#define DEMUSE_PLAYABLE_H

#include "symbol/Primitive.h"

namespace dem {
    namespace parser {
        class Playable : public Primitive {
        public:
            virtual bool accept(Visitor &visitor) = 0;
        };
    }
}

#endif //DEMUSE_PLAYABLE_H

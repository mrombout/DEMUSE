#ifndef DEMUSE_PLAYABLE_H
#define DEMUSE_PLAYABLE_H

#include "symbol/Primitive.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents a single playable entity
         * NOTE: Is this still useful?
         */
        class Playable : public Primitive {
        public:
            Playable(const lexer::Token &token) :
                    Primitive(token) {

            }
            virtual bool accept(Visitor &visitor) = 0;
        };
    }
}

#endif //DEMUSE_PLAYABLE_H

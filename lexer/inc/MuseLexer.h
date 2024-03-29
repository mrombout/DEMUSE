#ifndef DEMUSE_MUSELEXER_H
#define DEMUSE_MUSELEXER_H

#include "Lexer.h"

namespace dem {
    namespace lexer {
        /**
         * \brief Lexes a DEMUSE script.
         */
        class MuseLexer : public Lexer {
        public:
            MuseLexer();
        };
    }
}

#endif //DEMUSE_MUSELEXER_H

#ifndef DEMUSE_MUSICSTRINGLEXER_H
#define DEMUSE_MUSICSTRINGLEXER_H

#include "Lexer.h"
#include "matcher/RegexMatcher.h"
#include "matcher/CharMatcher.h"

namespace dem {
    namespace lexer {
        /**
         * \brief Lexes a DEMUSE sequence.
         */
        class MusicStringLexer : public Lexer {
        public:
            MusicStringLexer();
        };
    }
}

#endif //DEMUSE_MUSICSTRINGLEXER_H

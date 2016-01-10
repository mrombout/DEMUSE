#ifndef DEMUSE_PLAYMATCHER_H
#define DEMUSE_PLAYMATCHER_H

#include <string>
#include "matcher/Matcher.h"
#include "matcher/StringMatcher.h"
#include "MusicStringLexer.h"

namespace dem {
    namespace lexer {
        /**
         * \brief Matches an entire MusePlay sequence. Always returns the play closing characters ">>".
         *
         * NOTE: This matcher modifies the iterators, tokens and tokenPositions.
         */
        class PlayMatcher : public Matcher {
        public:
            PlayMatcher();
            virtual std::string match(std::string::iterator &begin, std::string::iterator &end, std::vector<Token> &tokens, TokenPosition &tokenPosition) const;

        private:
            StringMatcher mStartMatcher;
            MusicStringLexer mLexer;

        };
    }
}

#endif //DEMUSE_PLAYMATCHER_H

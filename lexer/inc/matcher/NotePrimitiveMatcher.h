#ifndef DEMUSE_NOTEPRIMITIVEMATCHER_H
#define DEMUSE_NOTEPRIMITIVEMATCHER_H

#include "Matcher.h"
#include "MusicStringLexer.h"
#include "StringMatcher.h"
#include "NoteMatcher.h"
#include "OctaveMatcher.h"
#include "AccidentalMatcher.h"
#include "DurationMatcher.h"
#include "CharMatcher.h"

namespace dem {
    namespace lexer {
        class NotePrimitiveMatcher : public Matcher {
        public:
            NotePrimitiveMatcher();

            virtual std::string match(std::string::iterator &begin, std::string::iterator &end, std::vector<Token> &tokens, TokenPosition &tokenPosition) const;

        private:
            CharMatcher mNotePrimitiveMatcher;
            NoteMatcher mNoteMatcher;
            OctaveMatcher mOctaveMatcher;
            AccidentalMatcher mAccidentalMatcher;
            DurationMatcher mDurationMatcher;
        };
    }
}

#endif //DEMUSE_NOTEPRIMITIVEMATCHER_H

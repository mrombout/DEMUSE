#ifndef DEMUSE_NOTEPRIMITIVEMATCHER_H
#define DEMUSE_NOTEPRIMITIVEMATCHER_H

#include "Matcher.h"
#include "MusicStringLexer.h"
#include "StringMatcher.h"
#include "matcher/NoteMatcher.h"

namespace dem {
    namespace lexer {
        class NotePrimitiveMatcher : public Matcher {
        public:
            NotePrimitiveMatcher();
            virtual std::string match(std::string::iterator &begin, std::string::iterator &end, std::vector<Token> &tokens) const;
        };
    }
}

#endif //DEMUSE_NOTEPRIMITIVEMATCHER_H

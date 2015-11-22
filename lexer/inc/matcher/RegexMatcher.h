#ifndef DEMUSE_REGEXMATCHER_H
#define DEMUSE_REGEXMATCHER_H

#include <regex>
#include "Matcher.h"

namespace dem {
    namespace lexer {
        class RegexMatcher : public Matcher {
        public:
            RegexMatcher(std::string regex);

            virtual std::string match(std::string::iterator &begin, std::string::iterator &end, std::vector<Token> &tokens) const;

        private:
            std::regex mRegex;
        };
    }
}

#endif //DEMUSE_REGEXMATCHER_H

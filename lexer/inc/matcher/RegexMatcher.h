#ifndef DEMUSE_REGEXMATCHER_H
#define DEMUSE_REGEXMATCHER_H

#include <regex>
#include "Matcher.h"

namespace dem {
    namespace lexer {
        /**
         * \brief Matches a string according to a regular expression.
         *
         * \note RegexMatcher should be used sparingly, as it can be slow.
         */
        class RegexMatcher : public Matcher {
        public:
            RegexMatcher(std::string regex);

            virtual std::string match(std::string::iterator &begin, std::string::iterator &end, std::vector<Token> &tokens, TokenPosition &tokenPosition) const;

            std::string regex() const;

        private:
            std::string mRegexStr;
            std::regex mRegex;
        };
    }
}

#endif //DEMUSE_REGEXMATCHER_H

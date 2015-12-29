#include "matcher/MultiCommentMatcher.h"

namespace dem {
    namespace lexer {
        std::string MultiCommentMatcher::match(std::string::iterator &begin, std::string::iterator &end, std::vector<Token> &tokens, TokenPosition &tokenPosition) const {
            std::string::iterator newBegin = begin;
            std::string::iterator newEnd = end;
            std::string matchResult;

            // "/*"
            if(!matchOpen(newBegin, newEnd))
                return "";
            matchResult += "/*";

            // match until "*/"
            while(!matchClose(newBegin, newEnd) && newBegin != newEnd) {
                matchResult += *newBegin;
                ++newBegin;
            }

            // "*/"
            if(matchClose(newBegin, newEnd))
                matchResult += "*/";

            return matchResult;
        }

        bool MultiCommentMatcher::matchOpen(std::string::iterator &begin, std::string::iterator &end) const {
            if(*begin != '/')
                return false;
            ++begin;
            if(*begin != '*')
                return false;
            ++begin;

            return true;
        }

        bool MultiCommentMatcher::matchClose(std::string::iterator begin, std::string::iterator end) const {
            if(*begin != '*')
                return false;
            ++begin;
            if(*begin != '/')
                return false;
            ++begin;

            return true;
        }
    }
}
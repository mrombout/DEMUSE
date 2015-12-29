#include "matcher/NewLineMatcher.h"

namespace dem {
    namespace lexer {
        std::string NewLineMatcher::match(std::string::iterator &begin, std::string::iterator &end, std::vector<Token> &tokens, TokenPosition &tokenPosition) const {
            std::string::iterator newBegin = begin;
            std::string::iterator newEnd = end;

            std::string newLine;
            if(*newBegin == '\r') {
                newLine += '\r';
                newBegin++;
            }
            if(*newBegin == '\n') {
                newLine += '\n';
                newBegin++;
            }

            return newLine;
        }
    }
}

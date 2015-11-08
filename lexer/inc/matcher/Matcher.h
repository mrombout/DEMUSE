#ifndef DEMUSE_MATCHER_H
#define DEMUSE_MATCHER_H

#include <string>

namespace dem {
    namespace lexer {
        class Matcher {
        public:
            virtual std::string match(std::string::iterator begin, std::string::iterator end) const = 0;
        };
    }
}

#endif //DEMUSE_MATCHER_H

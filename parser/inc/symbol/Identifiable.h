#ifndef DEMUSE_IDENTIFIABLE_H
#define DEMUSE_IDENTIFIABLE_H

#include <string>

namespace dem {
    namespace parser {
        class Identifiable {
        public:
            virtual const std::string &name() const = 0;
        };
    }
}

#endif //DEMUSE_IDENTIFIABLE_H

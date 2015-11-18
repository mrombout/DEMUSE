#ifndef DEMUSE_SYMBOL_H
#define DEMUSE_SYMBOL_H

#include "Visitable.h"

namespace dem {
    namespace parser {
        class Symbol : public Visitable {
        public:
            virtual ~Symbol() = 0;
        };
    }
}

#endif //DEMUSE_SYMBOL_H

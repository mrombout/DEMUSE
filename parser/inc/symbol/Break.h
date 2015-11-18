#ifndef DEMUSE_BREAK_H
#define DEMUSE_BREAK_H

#include "symbol/Statement.h"

namespace dem {
    namespace parser {
        class Break : public Statement {

        public:
            virtual bool accept(Visitor &visitor);
        };
    }
}

#endif //DEMUSE_BREAK_H

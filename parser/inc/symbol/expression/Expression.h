#ifndef DEMUSE_EXPRESSION_H
#define DEMUSE_EXPRESSION_H

#include <string>
#include "../Statement.h"

namespace dem {
    namespace parser {
        class Expression : public Statement {
        public:
            virtual ~Expression() { }
        };
    }
}

#endif //DEMUSE_EXPRESSION_H

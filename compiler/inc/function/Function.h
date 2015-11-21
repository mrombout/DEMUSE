#ifndef DEMUSE_FUNCTION_H
#define DEMUSE_FUNCTION_H

#include "value/Value.h"

namespace dem {
    namespace compiler {
        class Scope;
    }
}

namespace dem {
    namespace parser {
        class Identifier;
    }
}

namespace dem {
    namespace compiler {
        class Function {
        public:
            virtual parser::Identifier &identifier() const = 0;
            virtual Value *execute(Scope &scope) const = 0;
        };
    }
}

#endif //DEMUSE_FUNCTION_H

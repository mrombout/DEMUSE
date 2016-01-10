#ifndef DEMUSE_SONGVALUE_H
#define DEMUSE_SONGVALUE_H

#include "ObjectValue.h"

namespace dem {
    namespace compiler {
        /**
         * \brief Represents a song value
         *
         * The Song object is the root object on the DEMUSE programming language, similar to the "Window" object in a
         * browser JavaScript environment. The Song value contains all useful variable and functions that are part of
         * the DEMUSE language.
         */
        class SongValue : public ObjectValue {
        public:
            SongValue();
        };
    }
}

#endif //DEMUSE_SONGVALUE_H

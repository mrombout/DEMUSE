#ifndef DEMUSE_NOTE_H
#define DEMUSE_NOTE_H

#include <string>
#include "symbol/Primitive.h"

namespace dem {
    namespace parser {
        class Note : public Primitive {
        public:
            Note();

            virtual bool accept(Visitor &visitor);

        private:
            std::string mNote;
        };
    }
}

#endif //DEMUSE_NOTE_H

#ifndef DEMUSE_NOTE_H
#define DEMUSE_NOTE_H

#include <string>
#include "symbol/Symbol.h"

namespace dem {
    namespace parser {
        class Note : public Symbol {
        public:
            Note();

            virtual bool accept(Visitor &visitor);

        private:
            std::string mNote;
        };
    }
}

#endif //DEMUSE_NOTE_H

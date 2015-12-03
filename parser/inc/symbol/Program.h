#ifndef DEMUSE_PROGRAM_H
#define DEMUSE_PROGRAM_H

#include <vector>
#include "symbol/Symbol.h"
#include "Statement.h"

namespace dem {
    namespace parser {
        class Track;
    }
}

namespace dem {
    namespace parser {
        class Program : public Symbol {
        public:
            Program(std::vector<Statement*> statements);
            virtual ~Program();

            const std::vector<Statement*> &statements() const;

            virtual bool accept(Visitor &visitor);

        private:
            std::vector<Statement*> mStatements;
        };
    }
}

#endif //DEMUSE_PROGRAM_H

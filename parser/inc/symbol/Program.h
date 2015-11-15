#ifndef DEMUSE_PROGRAM_H
#define DEMUSE_PROGRAM_H

#include <vector>
#include "symbol/Statement.h"
#include "symbol/Symbol.h"

namespace dem {
    namespace parser {
        class Program : public Symbol {
        public:
            Program(std::vector<Statement*> statements);


            virtual ~Program();

            const std::vector<Statement*> &statements() const;

        private:
            std::vector<Statement*> mStatements;
        };
    }
}

#endif //DEMUSE_PROGRAM_H

#ifndef DEMUSE_ASSIGNMENTFACTORY_H
#define DEMUSE_ASSIGNMENTFACTORY_H

#include <deque>
#include "Token.h"
#include "symbol/Assignment.h"

namespace dem {
    namespace parser {
        class AssignmentFactory {
        public:
            static Assignment *produce(std::deque<lexer::Token> &tokens);
        };
    }
}

#endif //DEMUSE_ASSIGNMENTFACTORY_H

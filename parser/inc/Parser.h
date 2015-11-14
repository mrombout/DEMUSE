#ifndef DEMUSE_PARSER_H
#define DEMUSE_PARSER_H

#include <vector>
#include "Parser.h"
#include "Symbol.h"
#include "Token.h"

namespace dem {
    namespace parser {
        class Parser {
        public:
            virtual Symbol parse(std::vector<lexer::Token> &symbols) = 0;
        };
    }
}

#endif //DEMUSE_PARSER_H

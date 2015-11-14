#ifndef DEMUSE_MUSEPARSER_H
#define DEMUSE_MUSEPARSER_H

#include "Parser.h"

namespace dem {
    namespace parser {
        class MuseParser : public Parser {
        public:
            virtual Symbol parse(std::vector<lexer::Token> &symbols);
        };
    }
}

#endif //DEMUSE_MUSEPARSER_H

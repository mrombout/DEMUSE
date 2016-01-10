#ifndef DEMUSE_MUSEPARSER_H
#define DEMUSE_MUSEPARSER_H

#include <vector>
#include "Parser.h"
#include "Token.h"

namespace dem {
    namespace parser {
        /**
         * \brief Parses a DEMUSE script and populated the ParseResults object with errors and warning when they occur
         */
        class MuseParser : public Parser {
        public:
            virtual ParseResults parse(std::vector<lexer::Token> &symbols);
        };
    }
}

#endif //DEMUSE_MUSEPARSER_H

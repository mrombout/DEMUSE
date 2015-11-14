#include <vector>
#include <deque>
#include "MuseParser.h"
#include "Symbol.h"
#include "factory/ProgramFactory.h"

namespace dem {
    namespace parser {
        dem::parser::Symbol MuseParser::parse(std::vector<lexer::Token> &tokens) {
            std::deque<lexer::Token> tokensDeque{tokens.begin(), tokens.end()};

            return ProgramFactory::produce(tokensDeque);
        }
    }
}

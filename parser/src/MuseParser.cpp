#include <vector>
#include <deque>
#include "MuseParser.h"
#include "symbol/Symbol.h"
#include "factory/ProgramFactory.h"

namespace dem {
    namespace parser {
        Symbol *MuseParser::parse(std::vector<lexer::Token> &tokens) {
            std::deque<lexer::Token> tokensDeque{tokens.begin(), tokens.end()};

            return ProgramFactory::produce(tokensDeque);
        }
    }
}

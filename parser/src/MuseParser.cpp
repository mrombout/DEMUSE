#include <vector>
#include <deque>
#include "MuseParser.h"
#include "symbol/Program.h"
#include "factory/ProgramFactory.h"

namespace dem {
    namespace parser {
        ParseResults MuseParser::parse(std::vector<lexer::Token> &tokens) {
            std::deque<lexer::Token> tokensDeque{tokens.begin(), tokens.end()};
            ParseResults parseResults;

            std::shared_ptr<Program> program{std::move(ProgramFactory::produce(tokensDeque, parseResults))};
            parseResults.setAstRoot(program);

            return parseResults;
        }
    }
}

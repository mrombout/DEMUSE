#include <vector>
#include "factory/BlockFactory.h"
#include "factory/StatementFactory.h"

namespace dem {
    namespace parser {
        Block *BlockFactory::produce(std::deque<lexer::Token> &tokens) {
            // block = "{" { statement } "}" ;

            std::vector<Statement*> statements;

            // "{"
            expect(tokens, lexer::TokenType::START);

            do {
                Statement *statement = StatementFactory::produce(tokens);
                statements.push_back(statement);
            } while(!tokens.front().is(lexer::TokenType::END));
        }
    }
}

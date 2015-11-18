#include <vector>
#include "factory/BlockFactory.h"
#include "factory/StatementFactory.h"
#include "symbol/Block.h"

namespace dem {
    namespace parser {
        Block *BlockFactory::produce(std::deque<lexer::Token> &tokens) {
            // block = "{" { statement } "}" ;

            std::vector<Statement*> statements;

            // "{"
            expect(tokens, lexer::TokenType::START);

            while(!tokens.front().is(lexer::TokenType::END)) {
                Statement *statement = StatementFactory::produce(tokens);
                statements.push_back(statement);
            };

            // "}"
            expect(tokens, lexer::TokenType::END);

            return new Block(statements);
        }
    }
}

#include <vector>
#include "factory/BlockFactory.h"
#include "factory/StatementFactory.h"
#include "symbol/Block.h"

namespace dem {
    namespace parser {
        Block *BlockFactory::produce(std::deque<lexer::Token> &tokens, ParseResults &results) {
            // block = "{" { statement } "}" ;

            std::vector<Statement*> statements;

            // "{"
            lexer::Token token = tokens.front();
            expect(tokens, lexer::TokenType::START, results);

            while(!tokens.front().is(lexer::TokenType::END) && !tokens.front().isEOF()) {
                Statement *statement = StatementFactory::produce(tokens, results);
                statements.push_back(statement);
            };

            // "}"
            expect(tokens, lexer::TokenType::END, results);

            return new Block(token, statements);
        }
    }
}

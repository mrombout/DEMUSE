#include "factory/WhileFactory.h"
#include "factory/ExpressionFactory.h"
#include "factory/BlockFactory.h"

namespace dem {
    namespace parser {
        While *WhileFactory::produce(std::deque<lexer::Token> &tokens) {
            // while_stmt = "while(" conditional ")" block ;

            // "while("
            expect(tokens, lexer::TokenType::WHILE);
            expect(tokens, lexer::TokenType::OPEN);

            // conditional
            Expression *expression = ExpressionFactory::produce(tokens);

            // ")"
            expect(tokens, lexer::TokenType::CLOSE);

            // block
            Block *block = BlockFactory::produce(tokens);

            return new While(expression, block);
        }
    }
}

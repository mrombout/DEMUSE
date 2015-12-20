#include "factory/WhileFactory.h"
#include "factory/ExpressionFactory.h"
#include "factory/BlockFactory.h"
#include "symbol/While.h"

namespace dem {
    namespace parser {
        While *WhileFactory::produce(std::deque<lexer::Token> &tokens, ParseResults &results) {
            // while_stmt = "while(" conditional ")" block ;

            // "while("
            expect(tokens, lexer::TokenType::WHILE, results);
            expect(tokens, lexer::TokenType::OPEN, results);

            // conditional
            Expression *expression = ExpressionFactory::produce(tokens, results);
            // TODO: Can expression ever be nullptr? If so, check and throw exception

            // ")"
            expect(tokens, lexer::TokenType::CLOSE, results);

            // block
            Block *block = BlockFactory::produce(tokens, results);

            return new While(expression, block);
        }
    }
}

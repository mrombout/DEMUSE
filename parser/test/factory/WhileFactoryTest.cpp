#include <gtest/gtest.h>
#include "factory/WhileFactory.h"
#include "symbol/While.h"
#include "symbol/Block.h"
#include "symbol/expression/Expression.h"

class WhileFactoryTest : public ::testing::Test {
protected:
    WhileFactoryTest() {

    }

    dem::parser::WhileFactory factory;
};

TEST_F(WhileFactoryTest, SimpleWhile) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::WHILE, "while",   0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,  "(",    0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::BOOL,  "true", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE, ")",    0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::START, "{",    0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::END,   "}",    0, 0, 0),
    };

    // act
    dem::parser::While *whileStatement = factory.produce(tokens);

    // assert
    ASSERT_TRUE(dynamic_cast<dem::parser::Expression*>(&whileStatement->expression()) != nullptr);
    ASSERT_EQ(typeid(dem::parser::Block), typeid(whileStatement->block()));
}

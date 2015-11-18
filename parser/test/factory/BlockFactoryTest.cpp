#include <gtest/gtest.h>
#include "factory/BlockFactory.h"
#include "symbol/Block.h"

class BlockFactoryTest : public ::testing::Test {
protected:
    BlockFactoryTest() {

    }

    dem::parser::BlockFactory factory;
};

TEST_F(BlockFactoryTest, NoStatements) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::START, "{",   0, 1, 1),
        dem::lexer::Token(dem::lexer::TokenType::END, "}",   0, 1, 1),
    };

    // act / assert
    ASSERT_NO_THROW({
        dem::parser::Block *block = factory.produce(tokens);

        // assert
        ASSERT_EQ(0, tokens.size());
    });
}

TEST_F(BlockFactoryTest, OneStatement) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::START, "{",   0, 1, 1),
        dem::lexer::Token(dem::lexer::TokenType::BREAK, "break", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::END, "}",   0, 1, 1),
    };

    // act / assert
    ASSERT_NO_THROW({
        dem::parser::Block *block = factory.produce(tokens);

        // assert
        ASSERT_EQ(0, tokens.size());
        ASSERT_EQ(1, block->statements().size());
    });
}

TEST_F(BlockFactoryTest, ThreeStatements) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::START, "{",   0, 1, 1),
        dem::lexer::Token(dem::lexer::TokenType::BREAK, "break", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::BREAK, "break", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::BREAK, "break", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::END, "}",   0, 1, 1),
    };

    // act / assert
    ASSERT_NO_THROW({
        dem::parser::Block *block = factory.produce(tokens);

        // assert
        ASSERT_EQ(0, tokens.size());
        ASSERT_EQ(3, block->statements().size());
    });
}
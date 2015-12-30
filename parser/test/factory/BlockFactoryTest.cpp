#include <gtest/gtest.h>
#include "factory/BlockFactory.h"
#include "symbol/Block.h"

class BlockFactoryTest : public ::testing::Test {
protected:
    BlockFactoryTest() {

    }

    dem::lexer::TokenPosition tokenPosition;
    dem::parser::BlockFactory factory;

    dem::parser::ParseResults parseResults;
};

TEST_F(BlockFactoryTest, NoStatements) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::START, "{", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::END, "}", tokenPosition),
    };

    // act / assert
    ASSERT_NO_THROW({
        dem::parser::Block *block = factory.produce(tokens, parseResults);

        // assert
        ASSERT_EQ(0, tokens.size());
    });
}

TEST_F(BlockFactoryTest, OneStatement) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::START, "{", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BREAK, "break", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::END, "}", tokenPosition),
    };

    // act / assert
    ASSERT_NO_THROW({
        dem::parser::Block *block = factory.produce(tokens, parseResults);

        // assert
        ASSERT_EQ(0, tokens.size());
        ASSERT_EQ(1, block->statements().size());
    });
}

TEST_F(BlockFactoryTest, ThreeStatements) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::START, "{", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BREAK, "break", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BREAK, "break", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BREAK, "break", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::END, "}", tokenPosition),
    };

    // act / assert
    ASSERT_NO_THROW({
        dem::parser::Block *block = factory.produce(tokens, parseResults);

        // assert
        ASSERT_EQ(0, tokens.size());
        ASSERT_EQ(3, block->statements().size());
    });
}
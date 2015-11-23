#include <gtest/gtest.h>
#include <exception/ParsingException.h>
#include "factory/WhileFactory.h"
#include "symbol/While.h"
#include "symbol/Block.h"
#include "symbol/expression/Expression.h"

class WhileFactoryTest : public ::testing::Test {
protected:
    WhileFactoryTest() {

    }
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
    dem::parser::While *whileStatement = dem::parser::WhileFactory::produce(tokens);

    // assert
    ASSERT_TRUE(dynamic_cast<dem::parser::Expression*>(&whileStatement->expression()) != nullptr);
    ASSERT_EQ(typeid(dem::parser::Block), typeid(whileStatement->block()));
}

TEST_F(WhileFactoryTest, Error_ForgetWhile) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
            //dem::lexer::Token(dem::lexer::TokenType::WHILE, "while",   0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::OPEN,  "(",    0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::BOOL,  "true", 0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::CLOSE, ")",    0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::START, "{",    0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::END,   "}",    0, 0, 0),
    };

    // act / assert
    EXPECT_THROW({ dem::parser::WhileFactory::produce(tokens); }, dem::parser::ParsingException);
}

TEST_F(WhileFactoryTest, Error_ForgetOpen) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
            dem::lexer::Token(dem::lexer::TokenType::WHILE, "while",   0, 0, 0),
            //dem::lexer::Token(dem::lexer::TokenType::OPEN,  "(",    0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::BOOL,  "true", 0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::CLOSE, ")",    0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::START, "{",    0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::END,   "}",    0, 0, 0),
    };

    // act / assert
    EXPECT_THROW({ dem::parser::WhileFactory::produce(tokens); }, dem::parser::ParsingException);
}


TEST_F(WhileFactoryTest, Error_ForgetCondition) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
            dem::lexer::Token(dem::lexer::TokenType::WHILE, "while",   0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::OPEN,  "(",    0, 0, 0),
            //dem::lexer::Token(dem::lexer::TokenType::BOOL,  "true", 0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::CLOSE, ")",    0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::START, "{",    0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::END,   "}",    0, 0, 0),
    };

    // act / assert
    EXPECT_THROW({ dem::parser::WhileFactory::produce(tokens); }, dem::parser::ParsingException);
}

TEST_F(WhileFactoryTest, Error_ForgetClose) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
            dem::lexer::Token(dem::lexer::TokenType::WHILE, "while",   0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::OPEN,  "(",    0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::BOOL,  "true", 0, 0, 0),
            //dem::lexer::Token(dem::lexer::TokenType::CLOSE, ")",    0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::START, "{",    0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::END,   "}",    0, 0, 0),
    };

    // act / assert
    EXPECT_THROW({ dem::parser::WhileFactory::produce(tokens); }, dem::parser::ParsingException);
}

TEST_F(WhileFactoryTest, Error_ForgetBlock) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
            dem::lexer::Token(dem::lexer::TokenType::WHILE, "while",   0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::OPEN,  "(",    0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::BOOL,  "true", 0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::CLOSE, ")",    0, 0, 0),
            //dem::lexer::Token(dem::lexer::TokenType::START, "{",    0, 0, 0),
            //dem::lexer::Token(dem::lexer::TokenType::END,   "}",    0, 0, 0),
    };

    // act / assert
    EXPECT_THROW({ dem::parser::WhileFactory::produce(tokens); }, dem::parser::ParsingException);
}

TEST_F(WhileFactoryTest, Error_ForgetStart) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
            dem::lexer::Token(dem::lexer::TokenType::WHILE, "while",   0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::OPEN,  "(",    0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::BOOL,  "true", 0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::CLOSE, ")",    0, 0, 0),
            //dem::lexer::Token(dem::lexer::TokenType::START, "{",    0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::END,   "}",    0, 0, 0),
    };

    // act / assert
    EXPECT_THROW({ dem::parser::WhileFactory::produce(tokens); }, dem::parser::ParsingException);
}

TEST_F(WhileFactoryTest, Error_ForgetEnd) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
            dem::lexer::Token(dem::lexer::TokenType::WHILE, "while",   0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::OPEN,  "(",    0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::BOOL,  "true", 0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::CLOSE, ")",    0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::START, "{",    0, 0, 0),
            //dem::lexer::Token(dem::lexer::TokenType::END,   "}",    0, 0, 0),
    };

    // act / assert
    EXPECT_THROW({ dem::parser::WhileFactory::produce(tokens); }, dem::parser::ParsingException);
}
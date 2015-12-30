#include <gtest/gtest.h>
#include "symbol/Block.h"
#include "symbol/Break.h"
#include "symbol/Identifier.h"
#include "symbol/If.h"
#include "factory/IfFactory.h"
#include "exception/ParsingException.h"

class IfFactoryTest : public ::testing::Test {
protected:
    IfFactoryTest() {

    }

    dem::lexer::TokenPosition tokenPosition;

    dem::parser::ParseResults parseResults;
};

TEST_F(IfFactoryTest, IfNoBlock) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IF,         "if",    tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(",     tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BOOL,       "true",  tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")",     tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BREAK,      "break", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     tokenPosition),
    };

    // act
    dem::parser::If *ifStatement = dem::parser::IfFactory::produce(tokens, parseResults);

    // assert
    ASSERT_TRUE(dynamic_cast<dem::parser::Expression*>(&ifStatement->expression()) != nullptr);
    ASSERT_EQ(typeid(dem::parser::Block), typeid(ifStatement->block()));
}

TEST_F(IfFactoryTest, IfOnly) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IF,    "if",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,  "(",    tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BOOL,  "true", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE, ")",    tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::START, "{",    tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::END,   "}",    tokenPosition),
    };

    // act
    dem::parser::If *ifStatement = dem::parser::IfFactory::produce(tokens, parseResults);

    // assert
    ASSERT_TRUE(dynamic_cast<dem::parser::Expression*>(&ifStatement->expression()) != nullptr);
    ASSERT_EQ(typeid(dem::parser::Block), typeid(ifStatement->block()));
    ASSERT_TRUE(ifStatement->elseBlock() == nullptr);
}

TEST_F(IfFactoryTest, IfElse) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IF,    "if", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,  "(", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BOOL,  "true", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE, ")", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::START, "{", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::END,   "}", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::ELSE,  "else", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::START, "{", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::END,   "}", tokenPosition),
    };

    // act
    dem::parser::If *ifStatement = dem::parser::IfFactory::produce(tokens, parseResults);

    // assert
    ASSERT_TRUE(dynamic_cast<dem::parser::Expression*>(&ifStatement->expression()) != nullptr);
    ASSERT_EQ(typeid(dem::parser::Block), typeid(ifStatement->block()));
    ASSERT_EQ(typeid(dem::parser::Block), typeid(*ifStatement->elseBlock()));
}

TEST_F(IfFactoryTest, IfElseNoBlock) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IF,         "if", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BOOL,       "true", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BREAK,      "break", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::ELSE,       "else", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BREAK,      "break", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition)
    };

    // act
    dem::parser::If *ifStatement = dem::parser::IfFactory::produce(tokens, parseResults);

    // assert
    ASSERT_TRUE(dynamic_cast<dem::parser::Expression*>(&ifStatement->expression()) != nullptr);
    ASSERT_EQ(typeid(dem::parser::Block), typeid(ifStatement->block()));
    ASSERT_EQ(typeid(dem::parser::Block), typeid(ifStatement->block()));
    // TODO: Test if first and only statement in block is BREAK
    // TODO: Test if first and only statement in block is BREAK
}

TEST_F(IfFactoryTest, IfBlockElseNoBlock) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IF,         "if",    tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(",     tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BOOL,       "true",  tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")",     tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::START,      "{",     tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BREAK,      "break", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::END,        "}",     tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::ELSE,       "else",  tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BREAK,      "break", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     tokenPosition)
    };

    // act
    dem::parser::If *ifStatement = dem::parser::IfFactory::produce(tokens, parseResults);

    // assert
    ASSERT_TRUE(dynamic_cast<dem::parser::Expression*>(&ifStatement->expression()) != nullptr);
    ASSERT_EQ(typeid(dem::parser::Block), typeid(ifStatement->block()));
    ASSERT_EQ(typeid(dem::parser::Block), typeid(ifStatement->block()));
    // TODO: Test if first and only statement in block is BREAK
}

TEST_F(IfFactoryTest, IfNoBlockElseBlock) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IF,         "if",    tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(",     tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BOOL,       "true",  tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")",     tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BREAK,      "break", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::ELSE,       "else",  tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::START,      "{",     tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BREAK,      "break", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::END,        "}",     tokenPosition)
    };

    // act
    dem::parser::If *ifStatement = dem::parser::IfFactory::produce(tokens, parseResults);

    // assert
    ASSERT_TRUE(dynamic_cast<dem::parser::Expression*>(&ifStatement->expression()) != nullptr);
    ASSERT_EQ(typeid(dem::parser::Block), typeid(ifStatement->block()));
    ASSERT_EQ(typeid(dem::parser::Block), typeid(ifStatement->block()));
    // TODO: Test if first and only statement in block is BREAK
}

TEST_F(IfFactoryTest, Error_ForgetOpen) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IF,    "if",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BOOL,  "true", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE, ")",    tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::START, "{",    tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::END,   "}",    tokenPosition),
    };

    // act / assert
    EXPECT_THROW({
         dem::parser::If *ifStatement = dem::parser::IfFactory::produce(tokens, parseResults);
    }, dem::parser::ParsingException);
}

TEST_F(IfFactoryTest, Error_ForgetClose) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IF,    "if",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,  "(",    tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BOOL,  "true", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::START, "{",    tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::END,   "}",    tokenPosition),
    };

    // act / assert
    EXPECT_THROW({
        dem::parser::If *ifStatement = dem::parser::IfFactory::produce(tokens, parseResults);
    }, dem::parser::ParsingException);
}

TEST_F(IfFactoryTest, Error_ForgetExpression) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IF,    "if",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,  "(",    tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE, ")",    tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::START, "{",    tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::END,   "}",    tokenPosition),
    };

    // act / assert
    EXPECT_THROW({
         dem::parser::If *ifStatement = dem::parser::IfFactory::produce(tokens, parseResults);
    }, dem::parser::ParsingException);
}

TEST_F(IfFactoryTest, Error_ForgetBlockOrStatement) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IF,    "if",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,  "(",    tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BOOL,  "true", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE, ")",    tokenPosition)
    };

    // act / assert
    EXPECT_THROW({
        dem::parser::If *ifStatement = dem::parser::IfFactory::produce(tokens, parseResults);
        std::cout << "Everything is just fine" << std::endl;
    }, dem::parser::ParsingException);
}

TEST_F(IfFactoryTest, Error_ForgetElseBlockOrStatement) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IF,    "if",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,  "(",    tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BOOL,  "true", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE, ")",    tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::START, "{",    tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::END,   "}",    tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::ELSE,  "else", tokenPosition),
    };

    // act / assert
    EXPECT_THROW({
        dem::parser::If *ifStatement = dem::parser::IfFactory::produce(tokens, parseResults);
    }, dem::parser::ParsingException);
}

TEST_F(IfFactoryTest, Error_NotAStatement) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IF,    "if",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,  "(",    tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BOOL,  "true", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE, ")",    tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::PLUS,  "+",    tokenPosition)
    };

    // act / assert
    EXPECT_THROW({
        dem::parser::If *ifStatement = dem::parser::IfFactory::produce(tokens, parseResults);
    }, dem::parser::ParsingException);
}


#include <gtest/gtest.h>
#include "symbol/Block.h"
#include "symbol/Break.h"
#include "symbol/Identifier.h"
#include "symbol/If.h"
#include "factory/IfFactory.h"

class IfFactoryTest : public ::testing::Test {
protected:
    IfFactoryTest() {

    }

    dem::parser::IfFactory factory;
};

TEST_F(IfFactoryTest, IfOnly) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IF,    "if",   0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,  "(",    0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::BOOL,  "true", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE, ")",    0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::START, "{",    0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::END,   "}",    0, 0, 0),
    };

    // act
    dem::parser::If *ifStatement = factory.produce(tokens);

    // assert
    ASSERT_TRUE(dynamic_cast<dem::parser::Expression*>(&ifStatement->expression()) != nullptr);
    ASSERT_EQ(typeid(dem::parser::Block), typeid(ifStatement->block()));
    ASSERT_TRUE(ifStatement->elseBlock() == nullptr);
}

TEST_F(IfFactoryTest, IfElse) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IF,    "if",   0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,  "(",    0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::BOOL,  "true", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE, ")",    0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::START, "{",    0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::END,   "}",    0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::ELSE,  "}",    0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::START, "}",    0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::END,   "}",    0, 0, 0),
    };

    // act
    dem::parser::If *ifStatement = factory.produce(tokens);

    // assert
    ASSERT_TRUE(dynamic_cast<dem::parser::Expression*>(&ifStatement->expression()) != nullptr);
    ASSERT_EQ(typeid(dem::parser::Block), typeid(ifStatement->block()));
    ASSERT_EQ(typeid(dem::parser::Block), typeid(*ifStatement->elseBlock()));
}

/*
TEST_F(IfFactoryTest, IfNoBlock) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IF,         "if",    0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::BOOL,       "true",  0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::BREAK,      "break", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
    };

    // act
    dem::parser::If *ifStatement = factory.produce(tokens);

    // assert
    //ASSERT_TRUE(dynamic_cast<dem::parser::Expression*>(&ifStatement->expression()) != nullptr);
    //ASSERT_EQ(typeid(dem::parser::Block), typeid(ifStatement->block()));
    // TODO: Test if first and only statement in block is BREAK
}
*/

TEST_F(IfFactoryTest, IfElseNoBlock) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IF,         "if",    0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::BOOL,       "true",  0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::BREAK,      "break", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::ELSE,       "else",  0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::BREAK,      "break", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0)
    };

    // act
    dem::parser::If *ifStatement = factory.produce(tokens);

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
        dem::lexer::Token(dem::lexer::TokenType::IF,         "if",    0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::BOOL,       "true",  0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::START,      "{",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::BREAK,      "break", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::END,        "}",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::ELSE,       "else",  0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::BREAK,      "break", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0)
    };

    // act
    dem::parser::If *ifStatement = factory.produce(tokens);

    // assert
    ASSERT_TRUE(dynamic_cast<dem::parser::Expression*>(&ifStatement->expression()) != nullptr);
    ASSERT_EQ(typeid(dem::parser::Block), typeid(ifStatement->block()));
    ASSERT_EQ(typeid(dem::parser::Block), typeid(ifStatement->block()));
    // TODO: Test if first and only statement in block is BREAK
}

TEST_F(IfFactoryTest, IfNoBlockElseBlock) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IF,         "if",    0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::BOOL,       "true",  0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::BREAK,      "break", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::ELSE,       "else",  0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::START,      "{",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::BREAK,      "break", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::END,        "}",     0, 0, 0)
    };

    // act
    dem::parser::If *ifStatement = factory.produce(tokens);

    // assert
    ASSERT_TRUE(dynamic_cast<dem::parser::Expression*>(&ifStatement->expression()) != nullptr);
    ASSERT_EQ(typeid(dem::parser::Block), typeid(ifStatement->block()));
    ASSERT_EQ(typeid(dem::parser::Block), typeid(ifStatement->block()));
    // TODO: Test if first and only statement in block is BREAK
}
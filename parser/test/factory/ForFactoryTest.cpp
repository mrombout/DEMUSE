#include <gtest/gtest.h>
#include "factory/ForFactory.h"
#include "symbol/VariableDeclaration.h"
#include "symbol/expression/SmallerThanCondition.h"
#include "symbol/For.h"
#include "exception/ParsingException.h"

class ForFactoryTest : public ::testing::Test {
protected:
    ForFactoryTest() {

    }

    dem::lexer::TokenPosition tokenPosition;
    dem::parser::ForFactory factory;

    dem::parser::ParseResults parseResults;
};

TEST_F(ForFactoryTest, EmptyFor) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::FOR,        "while", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::START,      "{", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::END,        "}", tokenPosition)
    };

    // act
    dem::parser::For *forStatement = factory.produce(tokens, parseResults);

    // assert
    ASSERT_TRUE(forStatement->initialization() == nullptr);
    ASSERT_TRUE(forStatement->condition() == nullptr);
    ASSERT_TRUE(forStatement->afterThought() == nullptr);
}

TEST_F(ForFactoryTest, VariableDefInitialization) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::FOR,        "while", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::VAR,        "var", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "i", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::ASSIGNMENT, "=", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "0", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::START,      "{", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::END,        "}", tokenPosition)
    };

    // act
    dem::parser::For *forStatement = factory.produce(tokens, parseResults);

    // assert
    ASSERT_TRUE(dynamic_cast<dem::parser::VariableDeclaration*>(forStatement->initialization()) != nullptr);
    ASSERT_TRUE(forStatement->condition() == nullptr);
    ASSERT_TRUE(forStatement->afterThought() == nullptr);
}

TEST_F(ForFactoryTest, AssignmentInitialization) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::FOR,        "while", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "i", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::ASSIGNMENT, "=", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "0", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::START,      "{", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::END,        "}", tokenPosition)
    };

    // act
    dem::parser::For *forStatement = factory.produce(tokens, parseResults);

    // assert
    ASSERT_TRUE(dynamic_cast<dem::parser::AssignmentExpression*>(forStatement->initialization()) != nullptr);
    ASSERT_TRUE(forStatement->condition() == nullptr);
    ASSERT_TRUE(forStatement->afterThought() == nullptr);
}

TEST_F(ForFactoryTest, ProperInitializationConditonalAndAfterThought) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
            dem::lexer::Token(dem::lexer::TokenType::FOR,        "while", tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(", tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::VAR,        "var", tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "i", tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::ASSIGNMENT, "=", tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "0", tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "i", tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::SM,         "<", tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "10", tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "i", tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::ASSIGNMENT, "=", tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "i", tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::PLUS,       "+", tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "1", tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")", tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::START,      "{", tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::END,        "}", tokenPosition)
    };

    // act
    dem::parser::For *forStatement = factory.produce(tokens, parseResults);

    // assert
    ASSERT_TRUE(dynamic_cast<dem::parser::VariableDeclaration*>(forStatement->initialization()) != nullptr);
    ASSERT_TRUE(dynamic_cast<dem::parser::SmallerThanCondition*>(forStatement->condition()) != nullptr);
    ASSERT_TRUE(dynamic_cast<dem::parser::AssignmentExpression*>(forStatement->afterThought()) != nullptr);
}

TEST_F(ForFactoryTest, Error_ForgetOpen) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::FOR,        "while", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::START,      "{", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::END,        "}", tokenPosition)
    };

    // act / assert
    EXPECT_THROW({ factory.produce(tokens, parseResults); }, dem::parser::ParsingException);
}

TEST_F(ForFactoryTest, Error_ForgetClose) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::FOR,        "while", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::START,      "{", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::END,        "}", tokenPosition)
    };

    // act / assert
    EXPECT_THROW({ factory.produce(tokens, parseResults); }, dem::parser::ParsingException);
}

TEST_F(ForFactoryTest, Error_ForgetStart) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::FOR,        "while", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::END,        "}", tokenPosition)
    };

    // act / assert
    EXPECT_THROW({ factory.produce(tokens, parseResults); }, dem::parser::ParsingException);
}

TEST_F(ForFactoryTest, Error_ForgetEnd) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::FOR,        "while", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::START,      "{", tokenPosition)
    };

    // act / assert
    EXPECT_THROW({ factory.produce(tokens, parseResults); }, dem::parser::ParsingException);
}

TEST_F(ForFactoryTest, Error_ForgetBlock) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::FOR,        "while", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")", tokenPosition)
    };

    // act / assert
    EXPECT_THROW({ factory.produce(tokens, parseResults); }, dem::parser::ParsingException);
}
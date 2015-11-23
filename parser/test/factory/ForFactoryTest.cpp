#include <gtest/gtest.h>
#include "factory/ForFactory.h"
#include "symbol/VariableDeclaration.h"
#include "symbol/expression/SmallerThanCondition.h"
#include "symbol/expression/Expression.h"
#include "symbol/For.h"
#include "exception/ParsingException.h"

class ForFactoryTest : public ::testing::Test {
protected:
    ForFactoryTest() {

    }

    dem::parser::ForFactory factory;
};

TEST_F(ForFactoryTest, EmptyFor) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::FOR,        "while", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::START,      "{",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::END,        "}",     0, 0, 0)
    };

    // act
    dem::parser::For *forStatement = factory.produce(tokens);

    // assert
    ASSERT_TRUE(forStatement->initialization() == nullptr);
    ASSERT_TRUE(forStatement->condition() == nullptr);
    ASSERT_TRUE(forStatement->afterThought() == nullptr);
}

TEST_F(ForFactoryTest, VariableDefInitialization) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::FOR,        "while", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::VAR,        "var",   0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "i",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::ASSIGNMENT, "=",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "0",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::START,      "{",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::END,        "}",     0, 0, 0)
    };

    // act
    dem::parser::For *forStatement = factory.produce(tokens);

    // assert
    ASSERT_TRUE(dynamic_cast<dem::parser::VariableDeclaration*>(forStatement->initialization()) != nullptr);
    ASSERT_TRUE(forStatement->condition() == nullptr);
    ASSERT_TRUE(forStatement->afterThought() == nullptr);
}

TEST_F(ForFactoryTest, AssignmentInitialization) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::FOR,        "while", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "i",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::ASSIGNMENT, "=",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "0",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::START,      "{",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::END,        "}",     0, 0, 0)
    };

    // act
    dem::parser::For *forStatement = factory.produce(tokens);

    // assert
    ASSERT_TRUE(dynamic_cast<dem::parser::AssignmentExpression*>(forStatement->initialization()) != nullptr);
    ASSERT_TRUE(forStatement->condition() == nullptr);
    ASSERT_TRUE(forStatement->afterThought() == nullptr);
}

TEST_F(ForFactoryTest, ProperInitializationConditonalAndAfterThought) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
            dem::lexer::Token(dem::lexer::TokenType::FOR,        "while", 0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(",     0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::VAR,        "var",   0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "i",     0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::ASSIGNMENT, "=",     0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "0",     0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "i",     0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::SM,         "<",     0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "10",     0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "i",     0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::ASSIGNMENT, "=",     0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "i",     0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::PLUS,       "+",     0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "1",     0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")",     0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::START,      "{",     0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::END,        "}",     0, 0, 0)
    };

    // act
    dem::parser::For *forStatement = factory.produce(tokens);

    // assert
    ASSERT_TRUE(dynamic_cast<dem::parser::VariableDeclaration*>(forStatement->initialization()) != nullptr);
    ASSERT_TRUE(dynamic_cast<dem::parser::SmallerThanCondition*>(forStatement->condition()) != nullptr);
    ASSERT_TRUE(dynamic_cast<dem::parser::AssignmentExpression*>(forStatement->afterThought()) != nullptr);
}

TEST_F(ForFactoryTest, Error_ForgetOpen) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::FOR,        "while", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::START,      "{",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::END,        "}",     0, 0, 0)
    };

    // act / assert
    EXPECT_THROW({ factory.produce(tokens); }, dem::parser::ParsingException);
}

TEST_F(ForFactoryTest, Error_ForgetClose) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::FOR,        "while", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::START,      "{",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::END,        "}",     0, 0, 0)
    };

    // act / assert
    EXPECT_THROW({ factory.produce(tokens); }, dem::parser::ParsingException);
}

TEST_F(ForFactoryTest, Error_ForgetStart) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::FOR,        "while", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::END,        "}",     0, 0, 0)
    };

    // act / assert
    EXPECT_THROW({ factory.produce(tokens); }, dem::parser::ParsingException);
}

TEST_F(ForFactoryTest, Error_ForgetEnd) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::FOR,        "while", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::START,      "{",     0, 0, 0)
    };

    // act / assert
    EXPECT_THROW({ factory.produce(tokens); }, dem::parser::ParsingException);
}

TEST_F(ForFactoryTest, Error_ForgetBlock) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::FOR,        "while", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";",     0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")",     0, 0, 0)
    };

    // act / assert
    EXPECT_THROW({ factory.produce(tokens); }, dem::parser::ParsingException);
}
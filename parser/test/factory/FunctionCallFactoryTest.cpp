#include <gtest/gtest.h>
#include "FunctionCallExpressionFactory.h"
#include "exception/ParsingException.h"

class FunctionCallFactoryTest : public ::testing::Test {
protected:
    FunctionCallFactoryTest() {

    }

    dem::lexer::TokenPosition tokenPosition;
    dem::parser::FunctionCallExpressionFactory factory;
};

TEST_F(FunctionCallFactoryTest, Produce_NoArguments) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "foo", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,       ")", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
    };

    // act
    dem::parser::FunctionCall *functionCall = dem::parser::FunctionCallExpressionFactory::produce(tokens);

    // assert
    ASSERT_TRUE(functionCall);
    ASSERT_FALSE(functionCall->argumentList());
}

TEST_F(FunctionCallFactoryTest, Produce_SingleArgument) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "foo", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "5", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,       ")", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
    };

    // act
    dem::parser::FunctionCall *functionCall = dem::parser::FunctionCallExpressionFactory::produce(tokens);

    // assert
    ASSERT_TRUE(functionCall);
    ASSERT_TRUE(functionCall->argumentList());
    ASSERT_EQ(1, functionCall->argumentList()->numArguments());
}

TEST_F(FunctionCallFactoryTest, Error_ForgetOpen) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "foo", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "5", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,       ")", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
    };

    // act
    dem::parser::FunctionCall *functionCall = dem::parser::FunctionCallExpressionFactory::produce(tokens);

    // assert
    ASSERT_FALSE(functionCall);
}

TEST_F(FunctionCallFactoryTest, Error_ForgetClose) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "foo", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "5", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
    };

    // act / assert
    ASSERT_THROW({ dem::parser::FunctionCallExpressionFactory::produce(tokens); }, dem::parser::ParsingException);
}

TEST_F(FunctionCallFactoryTest, Error_ForgetParenthesis) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "foo", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TERMINATOR, ";", tokenPosition),
    };

    // act
    dem::parser::FunctionCall *functionCall = dem::parser::FunctionCallExpressionFactory::produce(tokens);

    // assert
    ASSERT_FALSE(functionCall);
}
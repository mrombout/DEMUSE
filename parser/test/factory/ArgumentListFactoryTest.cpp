#include <gtest/gtest.h>
#include "factory/ArgumentListFactory.h"
#include "symbol/ArgumentList.h"

class ArgumentListFactoryTest : public ::testing::Test {
protected:
    ArgumentListFactoryTest() {

    }

    dem::lexer::TokenPosition tokenPosition;
    dem::parser::ArgumentListFactory factory;
};

// TODO: Most tests rely on the ExpressionFactory working, should refactor to remove static calls

TEST_F(ArgumentListFactoryTest, SingleIdentifierArgument) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "X", tokenPosition)
    };

    // act
    dem::parser::ArgumentList *result = factory.produce(tokens);

    // assert
    ASSERT_EQ(1, result->numArguments());
}

TEST_F(ArgumentListFactoryTest, SinglePrimitiveArgument) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", tokenPosition)
    };

    // act
    dem::parser::ArgumentList *result = factory.produce(tokens);

    // assert
    ASSERT_EQ(1, result->numArguments());
}

TEST_F(ArgumentListFactoryTest, ThreeArguments) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::COMMA,  ",", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "4", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::COMMA,  ",", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "3", tokenPosition),
    };

    // act
    dem::parser::ArgumentList *result = factory.produce(tokens);

    // assert
    ASSERT_EQ(3, result->numArguments());
}

TEST_F(ArgumentListFactoryTest, ThreeMixedPrimitiveAndIdentifierArguments) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "X", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::COMMA,      ",", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "4", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::COMMA,      ",", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "3", tokenPosition),
    };

    // act
    dem::parser::ArgumentList *result = factory.produce(tokens);

    // assert
    ASSERT_EQ(3, result->numArguments());
}
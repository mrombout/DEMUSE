#include <gtest/gtest.h>
#include "factory/ArgumentListFactory.h"
#include "symbol/ArgumentList.h"

class ArgumentListFactoryTest : public ::testing::Test {
protected:
    ArgumentListFactoryTest() {

    }

    dem::parser::ArgumentListFactory factory;
};

// TODO: Most tests rely on the ExpressionFactory working, should refactor to remove static calls

TEST_F(ArgumentListFactoryTest, SingleIdentifierArgument) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "X", 0, 0, 0)
    };

    // act
    dem::parser::ArgumentList *result = factory.produce(tokens);

    // assert
    ASSERT_EQ(1, result->numArguments());
}

TEST_F(ArgumentListFactoryTest, SinglePrimitiveArgument) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0)
    };

    // act
    dem::parser::ArgumentList *result = factory.produce(tokens);

    // assert
    ASSERT_EQ(1, result->numArguments());
}

TEST_F(ArgumentListFactoryTest, ThreeArguments) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::COMMA,  ",", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "4", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::COMMA,  ",", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "3", 0, 0, 0),
    };

    // act
    dem::parser::ArgumentList *result = factory.produce(tokens);

    // assert
    ASSERT_EQ(3, result->numArguments());
}

TEST_F(ArgumentListFactoryTest, ThreeMixedPrimitiveAndIdentifierArguments) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "X", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::COMMA,      ",", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "4", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::COMMA,      ",", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "3", 0, 0, 0),
    };

    // act
    dem::parser::ArgumentList *result = factory.produce(tokens);

    // assert
    ASSERT_EQ(3, result->numArguments());
}